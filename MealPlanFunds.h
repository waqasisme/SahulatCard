#ifndef MealPlanFunds_h_
#define MealPlanFunds_h_

#include "Account.h"
#include "MealPlan.h"
#include "TransferMealPlanFunds.h"

class MealPlanFunds: public Account {
private:
    const MealPlan* plan;
public:
    MealPlanFunds();
    MealPlanFunds(const MealPlan&); // copy constructor
	void addMealPlan(const MealPlan&); // add a meal plan
	void endMealPlan(Account&);     // remove meal plan, transfer funds to TMPF account
	bool purchase(const Money&);    // purchase function with discount
	void discount();                // no explanation or use for this function was provided
	void print(std::ostream&) const;    // show current balance

	MealPlanFunds operator = (const MealPlanFunds&); // assignment operator
	~MealPlanFunds();   // destructor
};

#endif // MealPlanFunds_h_
