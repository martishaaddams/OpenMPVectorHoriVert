#include<iostream>
#include<stdlib.h>
#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
//#pragma once
using namespace std;
class ComplexNumber
{

public:
    int a,b;
    void SetZero()
     {
         a=0;
         b=0;
     }
    ComplexNumber();

    ComplexNumber(const int c,const int d);
    ComplexNumber(const ComplexNumber &b);
    const ComplexNumber operator +(const ComplexNumber& k);
    const ComplexNumber operator -(const ComplexNumber& k);
    ComplexNumber&  operator =(const ComplexNumber& k);
    const ComplexNumber operator*(const ComplexNumber& k);//multiplication of complex numbers
    void SetDate(int,int);
    void outp();
    friend int operator==(const ComplexNumber& k,const ComplexNumber& m);
    //int operator!=(const ComplexNumber& k)



};


#endif // COMPLEXNUMBER_H
