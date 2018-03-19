#ifndef FRACTION_H
#define FRACTION_H

#include<iostream>
using namespace std;


class Fraction 
{
public:
    //Data Memebers
    long long numerator;
    long long denominator;

    Fraction();

    //Parametrized constructor
    template<class Type1, class Type2>
    Fraction(Type1, Type2);

    //Destructor
    virtual ~Fraction(){};
    
    //Arithmetic Operators
    friend Fraction operator+(const Fraction&, const Fraction&);
    friend Fraction operator-(const Fraction&, const Fraction&);
    friend Fraction operator*(const Fraction&, const Fraction&);
    friend Fraction operator/(const Fraction&, const Fraction&);

    //Comparision operators
    friend bool operator>=(const Fraction&, const Fraction&);
    friend bool operator<=(const Fraction&, const Fraction&);
    friend bool operator==(const Fraction&, const Fraction&);
    friend bool operator!=(const Fraction&, const Fraction&);

    //Conversion Operators
    operator int(){return (numerator)/denominator;}
    operator float(){return ((float)numerator)/denominator;}
    operator double(){return ((double)numerator)/denominator;}
};

unsigned int gcd(unsigned int, unsigned int);
template<class Type>
Type check_overflow(Type);

#endif
