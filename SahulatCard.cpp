#include "SahulatCard.h"


//------------------------------[ANSWER TO QUESTION 1]-------------------------------------------------
SahulatCard::SahulatCard(const Student &S): s(const_cast<Student&>(S)), barcode(newBarcode()),
    PIN(0), active(false), expiry(Date().incYears(2)) // SahulatCard Constructor, with only active FlexAccount
{
    accounts[FLEX] = new FlexRupees();
	accounts[MEAL] = 0;
	accounts[TRANSFER] = 0;
}


//------------------------------[ANSWER TO QUESTION 2 (a)]------------------------------------------------
/** A default (compiler-generated) constructor does not exist for this class
    because we have already overridden it/defined our own parametrized version. **/

/** No the compiler generated versions (default versions) of the destructor,
    copy constructor and assignment operator for the SahulatCard class would
    not be appropriate. **/

/** This is because we have dynamically allocated space for elements of our
    accounts array. Thus we need to delete its contents ourselves when we're
    done with them. **/

/** Since this class consists of several pointer members, the default copy
    constructor and assignment operator would not be appropriate, as they
    would perform Shallow Copy operations, resulting in Memory Leaks and/or
    Dangling Pointers. **/

// All required members are defined below.

//-----------------------------------------------------------------------------------------------------
SahulatCard::~SahulatCard() // Destructor
{
    if(PIN)
    {
        delete PIN;
        PIN = 0;
    }

    if(accounts[FLEX])
    {
        delete accounts[FLEX];
        accounts[FLEX] = 0;
    }

    if(accounts[MEAL])
    {
        delete accounts[MEAL];
        accounts[MEAL] = 0;
    }

    if(accounts[TRANSFER])
    {
        delete accounts[TRANSFER];
        accounts[TRANSFER] = 0;
    }
}


//-----------------------------------------------------------------------------------------------------
SahulatCard::SahulatCard(const SahulatCard& Card2): s(Card2.s) // Copy Constructor
{
        // Copy automatic variables
    this->barcode = Card2.barcode;
    this->active = Card2.active;
    this->expiry = Card2.expiry;

        // if Card2 has active pointers, allocate space and copy VALUES
    if(Card2.PIN) *(this->PIN = new int) = *Card2.PIN;
        else this->PIN = 0;

    if(Card2.accounts[FLEX])
        *(this->accounts[FLEX] = new FlexRupees) = *Card2.accounts[FLEX];
    else this->accounts[FLEX] = 0;

    if(Card2.accounts[MEAL])
        *(this->accounts[MEAL] = new MealPlanFunds) = *Card2.accounts[MEAL];
    else this->accounts[MEAL] = 0;

    if(Card2.accounts[TRANSFER])
        *(this->accounts[TRANSFER] = new TransferMealPlanFunds) = *Card2.accounts[TRANSFER];
    else this->accounts[TRANSFER] = 0;

}


//-----------------------------------------------------------------------------------------------------
SahulatCard SahulatCard::operator = (const SahulatCard& Card2) // Assignment Operator
{
    if(this != &Card2)  // Check for self-assignment
    {
            // make automatic members equal
        this->barcode = Card2.barcode;
        this->active = Card2.active;
        this->expiry = Card2.expiry;

            // delete previously allocated heap memory
        if(this->PIN) delete this->accounts[FLEX];
        if(this->accounts[FLEX]) delete this->accounts[FLEX];
        if(this->accounts[MEAL]) delete this->accounts[FLEX];
        if(this->accounts[TRANSFER]) delete this->accounts[FLEX];

            // Copy VALUES (not addresses), if values don't exist, set pointers to null.
        if(Card2.PIN) *(this->PIN) = *Card2.PIN;
            else this->PIN = 0;

        if(Card2.accounts[FLEX]) *(this->accounts[FLEX]) = *Card2.accounts[FLEX];
            else this->accounts[FLEX] = 0;

        if(Card2.accounts[MEAL]) *(this->accounts[MEAL]) = *Card2.accounts[MEAL];
            else this->accounts[MEAL] = 0;

        if(Card2.accounts[TRANSFER]) *(this->accounts[TRANSFER]) = *Card2.accounts[TRANSFER];
            else this->accounts[TRANSFER] = 0;
    }

    return *this; // returned this object to make cascading possible
}


//------------------------------[ANSWER TO QUESTION 5]-------------------------------------------------
bool SahulatCard::purchase(AccountType t, const Money& amount)
{
    switch(t)
    {
case FLEX:
    return accounts[FLEX]->purchase(amount);
    break;

case MEAL:
    if(accounts[MEAL]->purchase(amount))
        return true;
    else return accounts[FLEX]->purchase(amount);
    break;

case TRANSFER:
    if(accounts[TRANSFER]->purchase(amount))
        return true;
    else return accounts[FLEX]->purchase(amount);
    break;

default: break;

    }

    return false;
}


//-----------------------------------------------------------------------------------------------------
void SahulatCard::addRupees(const Money& amount) // Cell FlexRupees' deposit function
{
    dynamic_cast<FlexRupees*>(accounts[FLEX])->Deposit(amount);
}


//-----------------------------------------------------------------------------------------------------
void SahulatCard::transactionHistory(std::ostream & out, const Date& start, const Date& end) const
{
    out << "\nPrinting All Transactions for Card: " << barcode << " from " <<
            start << " to " << end << std::endl;

    if(accounts[FLEX])
    {
        out << "\t\tFLEX RUPEES ACCOUNT:\n";
        accounts[FLEX]->transactionHistory(out, start, end);
    }

    if(accounts[MEAL])
    {
        out << "\n\t\tMEAL PLAN FUNDS ACCOUNT:\n";
        accounts[MEAL]->transactionHistory(out, start, end);
    }

    if(accounts[TRANSFER])
    {
        out << "\n\t\tTRANSFER MEAL PLAN FUNDS ACCOUNT:\n";
        accounts[TRANSFER]->transactionHistory(out, start, end);
    }

}


//---------------------------[Other Definitions (not required by Questions)]----------------------------
void SahulatCard::addMealPlan(const MealPlan& MPlan)
{
    if(accounts[MEAL]) delete accounts[MEAL];

    accounts[MEAL] = new MealPlanFunds(MPlan);
    accounts[FLEX]->purchase(MPlan.Initial());
}


//-----------------------------------------------------------------------------------------------------
void SahulatCard::endOfMealPlan()
{
    if(accounts[TRANSFER]) delete accounts[TRANSFER];

    accounts[TRANSFER] = new TransferMealPlanFunds();
    dynamic_cast<MealPlanFunds*>(accounts[MEAL])->endMealPlan(*accounts[TRANSFER]);
}


//-----------------------------------------------------------------------------------------------------
long SahulatCard::newBarcode() // random number generator for new bar-code
{
    static unsigned int m = 123456;
    static unsigned int n = 678910;

    m = 314258 * (m & 51) + (m >> 29);
    n = 112358 * (n & 53) + (n >> 23);

    return (m + n)%1000000 ;
}
