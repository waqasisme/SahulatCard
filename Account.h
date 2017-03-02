#ifndef Account_h_
#define Account_h_

#include <iostream>
#include <vector>
#include "Money.h"
#include "Date.h"
#include "Transaction.h"


//-----------------------------[ANSWER TO QUESTION 3]------------------------------------------------------

 // Account class Declaration
class Account {
private:
	Money balance;
protected:
    std::vector <Transaction> trans; // Array of composed objects of Transaction (since multiplicity was unbounded)
    Money getBal() const // Accessor for balance, NOT changing the public interface of Account
    {
        return balance;
    }

    void setBal(const Money& amount) // Mutator for balance, NOT changing the public interface of Account
    {
        balance = amount;
    }
public:
    Account(): balance(0, 0)
	{
	}

    Account(const Money& b): balance(b)
    {
    }

    void transactionHistory(std::ostream& out, const Date& start, const Date& end) const
    {
        out << "\n DATE\t\t|\tTRANS TYPE\t|\tAMOUNT\n";
        out << "--------------------------------------------------------------\n";

        for(unsigned int i=0; i < trans.size(); i++)
        {
            if(trans[i].getDate() >= start && trans[i].getDate() <= end)
            {
        out << " " << trans[i].getDate() << "\t|\t" << trans[i].getType() << "\t\t|\t" << trans[i].getAmount();
        out << "--------------------------------------------------------------\n";
            }

        }

        this->print(out);
    }

    virtual void print(std::ostream&) const = 0; // print function declared pure virtual making Account abstract

    virtual bool purchase(const Money &amount) // default definition of purchase function for account objects
    {
        if(amount <= balance)
        {
            balance = balance - amount;
            this->trans.push_back(Transaction(Date(), debit, amount));
            return true;
        }

        return false;
    }

    virtual ~Account() // destructor
    {
    }

};


#endif // Account_h_
