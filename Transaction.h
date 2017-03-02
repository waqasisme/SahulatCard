#ifndef Transaction_h_
#define Transaction_h_

enum Trans_Type {deposit, debit};

class Transaction {
private:
	Date date;
	Trans_Type type;
	Money amount;
public:
	Transaction(Date d, Trans_Type t, Money m): date(d), type(t), amount(m)
	{
	}

	Date getDate() const
	{
		return date;
	}

	std::string getType() const
	{
		if(type==deposit) return "DEPOSIT";
		if(type==debit) return "DEBIT";

		return "-----";
	}

	Money getAmount() const
	{
		return amount;
	}


	~Transaction()
	{
	}
};



#endif

