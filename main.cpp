/**
  *
  *            CP ASSIGNMENT # 3 - SAHULATCARD PROGRAM
  *     Dated: 10th May 2014
  *     GROUP SECTION: B1-CS
  *     Group Members:
  *       Saman Karim            (13K-2071)
  *       Muhammad Waqas Maqsood (13K-2185)
  *       Shireen Punjwani       (13K-2191)
  *       Ali Ghousuddin         (13K-2303)
  **/


#include <iostream>
#include "SahulatCard.h"

using namespace std;

/** Individual Answers may be found in the following locations:
    - Question 1, 2(a) and 5: Sahulat Card.cpp
    - Question 2(b) and 4: MealPlanFunds.cpp
    - Question 3: Account.h

    NOTE: Entire Program is designed to conform to the provided UML model,
        however Account parameter was removed from Transaction Constructor
        in order to avoid redundant code and recursive inclusion of headers.
            Since no specific container was referenced in the question, we
        have used a Vector to store all transactions.
            External libraries have been avoided, except <Vector> and <ctime>
        (for accurate date)
 */

int main()
{
    Student S;
    SahulatCard SCard(S);
    SahulatCard BCard(S);
    SahulatCard CCard(S);

    Money debS(500, 22);
    Money depS(15000);

    SCard.addRupees(depS);
    SCard.purchase(FLEX, debS);

    MealPlan M(Money(50), 50);
    SCard.addMealPlan(M);
    SCard.purchase(MEAL, Money(15));
    SCard.purchase(MEAL, Money(500));
    SCard.endOfMealPlan();

    Date start(12, 5, 2014);
    Date end(12, 5, 2014);

    SCard.transactionHistory(cout, start, end);



    return 0;
}
