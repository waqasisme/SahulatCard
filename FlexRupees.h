#ifndef FlexRupees_h_
#define FlexRupees_h_

#include "Account.h"

class FlexRupees: public Account {
public:
    FlexRupees(): Account()
    {
    }

    bool purchase(const Money& amount) // Purchase function that imposes 17% tax on purchase
    {
        return Account::purchase(amount + amount*0.17);
    }

    void Deposit(const Money& amount) // Add specified amount to account balance
    {
        setBal(getBal() + amount);
        trans.push_back(Transaction(Date(), deposit, amount));
    }

    void print(std::ostream& out) const // Overridden Pure Virtual Method
    {
        out << "\n Current Flex Rupees Account Balance: " << getBal() << std::endl;
    }

    ~FlexRupees() // Destructor
    {
    }

};



#endif

