#ifndef Money_h_
#define Money_h_

#include<iostream>

class Money {
private:
    long rupees, cents;
public:
	explicit Money(long=0, long=0);

	long Rupees() const; // Accessor - rupee value
	long Cents() const;  // Accessor - cents value

	Money operator + (const Money&) const; // Add two money values; return result
	Money operator - (const Money&) const; // Subtract n; return result
	Money operator * (int) const;          // Multiply by f%; return result

};
        // boolean overloaded operators for money class
bool operator == (const Money&, const Money&);
bool operator != (const Money&, const Money&);
bool operator < (const Money&, const Money&);
bool operator <= (const Money&, const Money&);
bool operator > (const Money&, const Money&);
bool operator >= (const Money&, const Money&);
        // insertion extraction operators for Money class
std::istream& operator >> (std::istream&, Money&);
std::ostream& operator << (std::ostream&, const Money&);

#endif
