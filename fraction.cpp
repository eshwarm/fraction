#include <iostream>
#include <fraction.h>
#include <limits.h>
#include <cmath>
#include<assert.h>
#include<vector>

Fraction::Fraction()
{
   //empty constructor

    numerator = 0;
    denominator = 1;
}

template<class Type1, class Type2>
Fraction::Fraction(Type1 n, Type2 d)
{

    /// Parametrized Constructor
    /**
    * @param n, d
    *    n is numerator, d is denominator.
    * @return
    *    doesn not return anything.
    * @throw
    *    throws an divide by zero exception.
    *    throws overflow exception.
    */

    if(d == 0)
    {
	throw std::overflow_error("Exception:Attempt to divide by zero");
    } else if(n == 0)
    {
	numerator = 0;
	denominator = 1;       
    } else
    {
	int sign = 1;     

        //Storing the sign of the value
	if(check_overflow(n) < 0 )
	{
	    sign *= -1;
	    n *= -1;
	}
        if(check_overflow(d) < 0 )
        {
            sign *= -1;
            d *= -1;
        }
        long long divisor = gcd(n, d);
	numerator  = n/(divisor * sign);
	denominator  = d/(divisor);
    }
}

template <class Type>
Type check_overflow(Type x)
{
    /// Checks overflow and underflow condition.
    /**
    * @param x
    *    x is any value of type int, float, double, long
    * @return
    *    return same value
    * @throw
    *    throws overflow exception.
    */

    if((x > LLONG_MAX) || (x < LLONG_MIN))
    {
        throw std::overflow_error("Exception:Integer overflow");
    } else
    {
        return x;
    }  
}

unsigned int gcd(unsigned int x, unsigned int y)
{
    /// Compute GCD
    /**
    * @param x, y
    * @return
    *   gcd of two values. 
    */

    if(x == 0)
    {
        return y;
    }
    return gcd(y%x, x);
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
    /// Operator overloading for addition
    /**
    * @param left, right
    *    left is object of first parameter, right is object of second parameter.
    * @return
    *    an object with sum of two fractions.
    */

    Fraction temp(left.numerator*right.denominator
                  +right.numerator*left.denominator,
                  left.denominator*right.denominator);
    return temp;
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
    /// Operator overloading for subtraction
    /**
    * @param left, right
    *    left is object of first parameter, right is object of second parameter.
    * @return
    *    an object with difference of two fractions.
    */

    Fraction temp(left.numerator*right.denominator
                  -right.numerator*left.denominator,
                  left.denominator*right.denominator);
    return temp;
}

Fraction operator*(const Fraction& left, const Fraction& right)
{
    /// Operator overloading for multiplication
    /**
    * @param left, right
    *    left is object of first parameter, right is object of second parameter.
    * @return
    *    an object with multiplication of two fractions.
    */

    Fraction temp(left.numerator*right.numerator,
                  left.denominator*right.denominator);
    return temp;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
    /// Operator overloading for division
    /**
    * @param left, right
    *    left is object of first parameter, right is object of second parameter.
    * @return
    *    an object with division of two fractions.
    */

    Fraction temp(left.numerator*right.denominator,
                  left.denominator*right.numerator);
    return temp;
}

bool operator==(const Fraction& left, const Fraction& right)
{
    /// Operator overloading for equality
    /**
    * @param left, right
    *    left is object of first parameter, right is object of second parameter.
    * @return
    *    a boolean value.
    */

    return (left.numerator == right.numerator) && 
                  (left.denominator == right.denominator);
    
}

bool operator!=(const Fraction& left, const Fraction& right)
{
    /// Operator overloading for not equal.
    /**
    * @param left, right
    *    left is object of first parameter, right is object of second parameter.
    * @return
    *    a boolean value.
    */
    return !(left == right);
}

bool operator>(const Fraction& left, const Fraction& right)
{
    /// Operator overloading for greater than.
    /**
    * @param left, right
    *    left is object of first parameter, right is object of second parameter.
    * @return
    *    a boolean value.
    */

    return ((left.numerator * right.denominator) - (right.numerator * left.denominator)) > 0;
}

bool operator<(const Fraction& left, const Fraction& right)
{
    /// Operator overloading for lesser than.
    /**
    * @param left, right
    *    left is object of first parameter, right is object of second parameter.
    * @return
    *    a boolean value.
    */

    return ((left.numerator * right.denominator) - (right.numerator * left.denominator)) < 0;
}

bool operator>=(const Fraction& left, const Fraction& right)
{
    /// Operator overloading for greater and equal than.
    /**
    * @param left, right
    *    left is object of first parameter, right is object of second parameter.
    * @return
    *    a boolean value.
    */

    return (left > right) or (left == right);
}

bool operator<=(const Fraction& left, const Fraction& right)
{
    /// Operator overloading for lesser and equal than.
    /**
    * @param left, right
    *    left is object of first parameter, right is object of second parameter.
    * @return
    *    a boolean value.
    */

    return (left < right) or (left == right);
}

std::ostream& operator<<(std::ostream &stream, const Fraction &obj) 
{
    if (obj.denominator == 1) 
    {
        stream << obj.numerator;
    } else 
    {
        stream << obj.numerator << "/" << obj.denominator;
    }
    return stream;
}

void test_add()
{
    /// Test addition.

    std::vector<long long> v = {99, 8, 2, 4, -99, 8, 2, 4, 0, 3, 2, 3, 7, -1, 1, 2};
    std::vector<long long> v1 = {103, 8, -95, 8, 2, 3, -13, 2};
    int j = 0;

    for(int i = 0; i < v.size(); i+=4)
    {   
        Fraction f1(v[i], v[i+1]);
        Fraction f2(v[i+2], v[i+3]);
        Fraction expected(v1[j], v1[j+1]);

        Fraction c = f1 + f2;

        //std::cout<<c.numerator<<" " <<c.denominator<<" " << j<<std::endl;
        assert(c.numerator == expected.numerator);
        assert(c.denominator == expected.denominator); 
        j += 2;
    }
}


void test_sub()
{
    /// Test subtraction
    std::vector<long long> v = {99, 8, 2, 4, -99, 8, 2, 4, 0, 3, 2, 3, 7, -1, 1, 2};
    std::vector<long long> v1 = {95, 8, -103, 8, -2, 3, -15, 2};
    int j = 0;

    for(int i = 0; i < v.size(); i+=4)
    {
        Fraction f1(v[i], v[i+1]);
        Fraction f2(v[i+2], v[i+3]);
        Fraction expected(v1[j], v1[j+1]);

        Fraction c = f1 - f2;

        //std::cout<<c.numerator<<" " <<c.denominator<<" " << j<<std::endl;
        assert(c.numerator == expected.numerator);
        assert(c.denominator == expected.denominator);
        j += 2;
    }    
}

void test_mul()
{
    /// Test Multiplication.

    std::vector<long long> v = {99, 8, 2, 4, -99, 8, 2, 4, 0, 3, 2, 3, 7, -1, 1, 2};
    std::vector<long long> v1 = {99, 16, -99, 16, 0, 6, -7, 2};
    int j = 0;

    for(int i = 0; i < v.size(); i+=4)
    {
        Fraction f1(v[i], v[i+1]);
        Fraction f2(v[i+2], v[i+3]);
        Fraction expected(v1[j], v1[j+1]);

        Fraction c = f1 * f2;

        assert(c.numerator == expected.numerator);
        assert(c.denominator == expected.denominator);
        j += 2;
    }
}

void test_div()
{
    /// Test division
    std::vector<long long> v = {99, 8, 2, 4, -99, 8, 2, 4, 0, 3, 2, 3, 7, -1, 1, 2};
    std::vector<long long> v1 = {99, 4, -99, 4, 0, 2, -14, 1};
    int j = 0;

    for(int i = 0; i < v.size(); i+=4)
    {
        Fraction f1(v[i], v[i+1]);
        Fraction f2(v[i+2], v[i+3]);
        Fraction expected(v1[j], v1[j+1]);

        Fraction c = f1 / f2;

        assert(c.numerator == expected.numerator);
        assert(c.denominator == expected.denominator);
        j += 2;
    }
}

void test_equal()
{
    /// Test both equla and not equal.
    std::vector<long long> v = {99, 8, 2, 4, -99, 8, 2, 4, 0, 3, 2, 3, 7, -1, 1, 2};
    std::vector<long long> v1 = {99, 4, -99, 4, 0, 2, -14, 1};
    int j = 0;

    for(int i = 0; i < v.size(); i+=4)
    {
        Fraction f1(v[i], v[i+1]);
        Fraction f2(v[i+2], v[i+3]);

        assert(f1 != f2);
    }    
}

void test_greater()
{
    /// Test both greater than and less than
    std::vector<long long> v = {99, 8, 2, 4, -99, 8, 2, 4, 0, 3, 2, 3, 7, -1, 1, 2};
    std::vector<long long> v1 = {99, 4, -99, 4, 0, 2, -14, 1};
    int j = 0;

    for(int i = 0; i < v.size(); i+=4)
    {
        Fraction f1(v[i], v[i+1]);
        Fraction f2(v[i+2], v[i+3]);
        if(f1 <= f2)
        {
          std::cout<<"less"<<std::endl;
        } else
        {
          std::cout<<"greater"<<std::endl;
        }
    }
}



int main()
{
    test_add();
    test_sub();
    test_mul();
    test_div();
    test_equal();
    test_greater();
}

