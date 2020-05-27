#ifndef CCOMPLEXVECTOR1_H
#define CCOMPLEXVECTOR1_H
#include "complexvector.hpp"
#include"fstream"


class CComplexVector1: public CComplexVector{
public:
    CComplexVector1():CComplexVector(){};
    CComplexVector1(const int k):CComplexVector(k){};
    CComplexVector1(const int k, const ComplexNumber *str): CComplexVector(k,str){};//*
    CComplexVector1(const CComplexVector& k):CComplexVector(k){};
    CComplexVector1(const int k,const std::string& filename):CComplexVector(k,filename){};
    const CComplexVector1 operator +(const CComplexVector1 &k );
    const CComplexVector1 operator -(const CComplexVector1 &k );
    const CComplexVector1 operator *(const CComplexVector1 &k );
    using CComplexVector::operator =;//check
    int output(const std::string& Filename);

};

#endif // CCOMPLEXVECTOR1_H
