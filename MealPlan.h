#ifndef MealPlan_h_
#define MealPlan_h_

#include "Money.h"

class MealPlan {
private:
    Money initialFunds;
    int discount;
        // Mutators kept private as per UML Diagram
    void InitialIs(const Money& M)
    {
        initialFunds = M;
    }

    void DiscountIs(int d)
    {
        discount = d;
    }
public:
    MealPlan(const Money& initFunds, int d): initialFunds(initFunds), discount(d) // Constructor
    {
    }

    Money Initial() const   // Accessor
    {
        return initialFunds;
    }

    int Discount() const    // Accessor
    {
        return discount;
    }

};

#endif // MealPlan_h_
