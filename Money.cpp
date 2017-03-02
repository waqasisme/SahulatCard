#include "Money.h"

//-----------------------------------------------------------------------------------------
Money::Money(long rs, long c): rupees(rs), cents(c)
{
}


//-----------------------------------------------------------------------------------------
long Money::Rupees() const
{
    return rupees;
}

//-----------------------------------------------------------------------------------------
long Money::Cents() const
{
    return cents;
}


//-----------------------------------------------------------------------------------------
Money Money::operator + (const Money& m2) const
{
    if(this->cents + m2.cents > 100)
        return Money(this->rupees + m2.rupees + 1, 100 - this->cents + m2.cents);

    return Money(this->rupees + m2.rupees, this->cents + m2.cents);
}

//-----------------------------------------------------------------------------------------
Money Money::operator - (const Money& m2) const
{
    if(this->cents < m2.cents)
        return Money(this->rupees - m2.rupees - 1, this->cents + 100 - m2.cents);


    return Money(this->rupees - m2.rupees, this->cents - m2.cents);
}

//-----------------------------------------------------------------------------------------
Money Money::operator * (int f) const
{
    return Money(this->rupees*f + (this->cents*f)/100, (this->cents*f)%100);
}


//-----------------------------------------------------------------------------------------
bool operator == (const Money& m1, const Money& m2)
{
    return (m1.Rupees() == m2.Rupees() && m1.Cents() == m2.Cents());
}

//-----------------------------------------------------------------------------------------
bool operator != (const Money& m1, const Money& m2)
{
    return !(m1 == m2);
}

//-----------------------------------------------------------------------------------------
bool operator < (const Money& m1, const Money& m2)
{
    if(m1.Rupees() < m2.Rupees()) return true;

    if(m1.Rupees() == m2.Rupees() && m1.Cents() < m2.Cents()) return true;

    return false;
}

//-----------------------------------------------------------------------------------------
bool operator <= (const Money& m1, const Money& m2)
{
    return (m1<m2 || m1==m2);
}

//-----------------------------------------------------------------------------------------
bool operator > (const Money& m1, const Money& m2)
{
    if(m1.Rupees() > m2.Rupees()) return true;

    if(m1.Rupees() == m2.Rupees() && m1.Cents() > m2.Cents()) return true;

    return false;
}

//-----------------------------------------------------------------------------------------
bool operator >= (const Money& m1, const Money& m2)
{
    return (m1>m2 || m1==m2);
}


//-----------------------------------------------------------------------------------------
std::ostream& operator << (std::ostream& out, const Money& M)
{
    out << M.Rupees() << "." << M.Cents() << " Rupees" << std::endl;

	return out;
}

//-----------------------------------------------------------------------------------------
std::istream& operator >> (std::istream& in, Money& M)
{
    long r, c;
    char d;

    in >> r >> d >> c;  // Input a money amount in the format Rs.Cents

    M = Money(r, c);

    return in;
}

