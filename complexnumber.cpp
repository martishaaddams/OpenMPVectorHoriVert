#include "complexnumber.h"

ComplexNumber::ComplexNumber()
{
    SetZero();
}

ComplexNumber::ComplexNumber(const int c,const int d)
{
    a=c;
    b=d;
}
ComplexNumber::ComplexNumber(const ComplexNumber &k)
    {
        a=k.a;
        b=k.b;
    }
const ComplexNumber ComplexNumber:: operator +(const ComplexNumber& k)
{
   ComplexNumber z;
   z.a=a+k.a;
   z.b=b+k.b;
   return z;
}
const ComplexNumber ComplexNumber::operator -(const ComplexNumber& k)
{
    ComplexNumber z;
    z.a=a-k.a;
    z.b=b-k.b;
    return z;
}
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& k)
{
    //ComplexNumber z;
    a=k.a;
    b=k.b;
    return *this;
}
const ComplexNumber ComplexNumber::operator*(const ComplexNumber& k)
{
    ComplexNumber z;
    z.a=(a*k.a)-(b*k.b);
    z.b=(a*k.b)+(k.a*b);
    return z;
}
void ComplexNumber::SetDate(int c,int d)
{
    a=c;
    b=d;

}
void ComplexNumber::outp()
{
    std::cout<<a;
    cout<<"+i*"<<b;

}
