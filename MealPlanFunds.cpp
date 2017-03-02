#include "MealPlanFunds.h"
#include "MealPlan.h"
#include "Transaction.h"
//------------------------------[ANSWER TO QUESTION 2 (b)]------------------------------------------------
MealPlanFunds MealPlanFunds::operator = (const MealPlanFunds& M2) // Assignment operator
{
    if(this != &M2)
    {
        this->setBal(M2.getBal());  // set balance equal

        this->plan = M2.plan;   // copy addresses, both objects share a mealplan

        this->trans.erase(trans.begin(), trans.end()); // delete old transactions

        for(unsigned int i=0; i < M2.trans.size();i++) // copy transaction history
            this->trans.push_back(M2.trans.at(i));
    }

    return *this;
}


//------------------------------[ANSWER TO QUESTION 4 (a)]------------------------------------------------
MealPlanFunds::MealPlanFunds(): Account(), plan(0)
{
}


//--------------------------------------------------------------------------------------------------------
MealPlanFunds::MealPlanFunds(const MealPlan& M): Account()
{
    plan = &M;
    this->setBal(M.Initial());
}


//------------------------------[ANSWER TO QUESTION 4 (b)]------------------------------------------------
bool MealPlanFunds::purchase(const Money &amount)
{
    float dp = static_cast<float>(plan->Discount())/100; // discount to applicate

    return Account::purchase(amount*dp);
}


//-------------------------------------------------------------------------------------------------------
void MealPlanFunds::addMealPlan(const MealPlan& M)
{
    plan = &M;
    this->setBal(M.Initial());
}


//------------------------------[ANSWER TO QUESTION 4 (c)]------------------------------------------------
void MealPlanFunds::endMealPlan(Account& ToAccount)
{
    dynamic_cast<TransferMealPlanFunds&>(ToAccount) = TransferMealPlanFunds(this->getBal());
    dynamic_cast<TransferMealPlanFunds&>(ToAccount).addMealPlan(*plan); // move this plan to TMPF account

    plan = 0;
}


//-------------------------------------------------------------------------------------------------------
void MealPlanFunds::print(std::ostream& out) const
{
    out << "\n Current Meal Plan Funds Account Balance: " << getBal() << std::endl;
}

//-------------------------------------------------------------------------------------------------------
MealPlanFunds::~MealPlanFunds()
{
    if(plan)
    plan = 0;
}
