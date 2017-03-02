#ifndef Date_h_
#define Date_h_

#include <iostream>
#include <ctime>

class Date {
private:
    int day;
    int month;
    int year;
public:
        // Constructors
    Date();                 // Returns today's date
    Date(int, int, int);   // Parameterized Constructor

        // Accessors
    int Day() const;
    int Month() const;
    int Year() const;

        // Increase date
    Date incDays(int) const;
    Date incMonths(int) const;
    Date incYears(int) const;

};

    // Boolean non-member overloaded operators
bool operator == (const Date&, const Date&);
bool operator != (const Date&, const Date&);
bool operator < (const Date&, const Date&);
bool operator <= (const Date&, const Date&);
bool operator > (const Date&, const Date&);
bool operator >= (const Date&, const Date&);

    // Overloaded non-member Insertion and Extraction Operators
std::ostream& operator << (std::ostream&, const Date&);
std::istream& operator >> (std::istream&, Date&);


#endif // Date_h_
