#ifndef TransferMealPlanFunds_h_
#define TransferMealPlanFunds_h_

#include "Account.h"
#include "MealPlan.h"

class TransferMealPlanFunds: public Account {
private:
    const MealPlan* plan;
public:
    TransferMealPlanFunds(const Money& amount= Money()): Account(amount), plan(0) // Constructor
    {
    }

    bool purchase(const Money&amount) // Purchase function with GST and Discount
    {
        if(!plan) return false;

        float dp = (static_cast<float>(plan->Discount())/100)*0.17;

        return Account::purchase(amount*dp);
    }

    void addMealPlan(const MealPlan& M) // Adding a new meal plan
    {
        plan = &M;
    }

    void print(std::ostream& out) const // Overridden Pure Virtual function
    {
        out << "\n Current Transfer Meal Plan Funds Account Balance: " << getBal() << std::endl;
    }

    ~TransferMealPlanFunds() // Destructor
    {
        plan = 0;
    }

};


#endif // TransferMealPlanFunds_h_
