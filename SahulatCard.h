#ifndef SahulatCard_h_
#define SahulatCard_h_

#include <iostream>
#include "Student.h"
#include "FlexRupees.h"
#include "MealPlanFunds.h"

enum AccountType {FLEX, MEAL, TRANSFER};

class SahulatCard {
private:
    static const int NUM = 3;
    Student &s;
    long barcode;
    int* PIN;
    bool active;
    Date expiry;
    Account* accounts[NUM];
    /* Assume that AccountType(above) indices denote type of Account (i.e accounts[FLEX] is a FlexRupees account */
    long newBarcode(); // Random Number Generator
public:
    SahulatCard(const Student&);    // constructor
    bool purchase(AccountType, const Money&);
    // debit amount from specified account; return success code
    void addMealPlan(const MealPlan&);
    // add meal plan to SahulatCard
    void endOfMealPlan();
    // remove meal plan; transfer unused funds to Transfer Meal Plan account */
    void addRupees(const Money&);
    // add money to FlexRupees account
    void transactionHistory(std::ostream &, const Date&, const Date&) const;
    // stream transactions for all accounts between start and end dates

    SahulatCard(const SahulatCard&);    // Copy Constructor
    SahulatCard operator = (const SahulatCard&);    // Assignment Operator
    ~SahulatCard();
};


#endif // SahulatCard_h_
