#include "Date.h"

//-----------------------------------------------------------------------------------------
Date::Date()    // Constructor that sets date to current date (localtime)
{
    time_t t = time(0);
    struct tm * now = localtime(&t);

    day = now->tm_mday;
    month = now->tm_mon + 1;
    year = now->tm_year + 1900;

}

//-----------------------------------------------------------------------------------------
Date::Date(int d, int m, int y): day(d), month(m), year(y)
{
}


//-----------------------------------------------------------------------------------------
int Date::Day() const
{
    return this->day;
}

//-----------------------------------------------------------------------------------------
int Date::Month() const
{
    return this->month;
}

//-----------------------------------------------------------------------------------------
int Date::Year() const
{
    return this->year;
}


//-----------------------------------------------------------------------------------------
Date Date::incDays(int d) const
{
    return(this->day+d > 30)?
        Date(this->day+d-30, this->month+1, this->year):Date(this->day+1, this->month, this->year);
}

//-----------------------------------------------------------------------------------------
Date Date::incMonths(int m) const
{
    return(this->month+m > 12)?
        Date(this->day, this->month+m-12, this->year+1):Date(this->day, this->month+m, this->year);
}

//-----------------------------------------------------------------------------------------
Date Date::incYears(int y) const
{
    return Date(this->day, this->month, this->year + y);
}


//-----------------------------------------------------------------------------------------
bool operator == (const Date& d1, const Date& d2)
{
    return (d1.Day()==d2.Day() && d1.Month()==d2.Month() && d1.Year()==d2.Year());
}

//-----------------------------------------------------------------------------------------
bool operator != (const Date& d1, const Date& d2)
{
    return !(d1==d2);
}

//-----------------------------------------------------------------------------------------
bool operator < (const Date& d1, const Date& d2)
{
    if(d1.Year() < d2.Year()) return true;
    if(d1.Year()==d2.Year() && d1.Month() < d2.Month()) return true;
    if(d1.Year()==d2.Year() && d1.Month()==d2.Month() && d1.Day() < d2.Day()) return true;

    return false;
}

//-----------------------------------------------------------------------------------------
bool operator <= (const Date& d1, const Date& d2)
{
    return (d1<d2 || d1==d2);
}

//-----------------------------------------------------------------------------------------
bool operator > (const Date& d1, const Date& d2)
{
    if(d1.Year() > d2.Year()) return true;
    if(d1.Year()==d2.Year() && d1.Month() > d2.Month()) return true;
    if(d1.Year()==d2.Year() && d1.Month()==d2.Month() && d1.Day() > d2.Day()) return true;

    return false;
}

//-----------------------------------------------------------------------------------------
bool operator >= (const Date& d1, const Date& d2)
{
    return (d1>d2 || d1==d2);
}


//-----------------------------------------------------------------------------------------
std::ostream& operator << (std::ostream& out, const Date& d)
{
    out << d.Day() << "/" << d.Month() << "/" << d.Year();

	return out;
}

//-----------------------------------------------------------------------------------------
std::istream& operator >> (std::istream& in, Date& D)
{
    int d, m, y;
    char c;

    in >> d >> c >> m >> c >> y;    // Input date in the format d/m/y

    D = Date(d, m, y);

    return in;
}
