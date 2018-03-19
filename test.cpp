#include <iostream>
#include "fraction.h"
#include <limits.h>
#include <cmath>
#include<assert.h>
#include<vector>

void test_add()
{
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
    std::vector<long long> v = {99, 8, 2, 4, -99, 8, 2, 4, 0, 3, 2, 3, 7, -1, 1, 2};
    std::vector<long long> v1 = {99, 16, -99, 16, 0, 6, -7, 2};
    int j = 0;

    for(int i = 0; i < v.size(); i+=4)
    {
        Fraction f1(v[i], v[i+1]);
        Fraction f2(v[i+2], v[i+3]);
        Fraction expected(v1[j], v1[j+1]);

        Fraction c = f1 * f2;

        //std::cout<<c.numerator<<" " <<c.denominator<<" " << j<<std::endl;
        assert(c.numerator == expected.numerator);
        assert(c.denominator == expected.denominator);
        j += 2;
    }
}

void test_div()
{
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

