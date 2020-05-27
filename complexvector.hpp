#ifndef CCOMPLEXVECTOR_H
#define CCOMPLEXVECTOR_H
#include "complexnumber.h"
#include<vector>
#include<chrono>
void scan(const std::string& inp);
class CComplexVector
{
public:
    int n;
    //char Filename[80];
    std::string Filename;
    std::string op = "with";
    //ComplexNumber *arr;
    std::vector<ComplexNumber> arr;
    CComplexVector();
    CComplexVector(const int k);
    CComplexVector(const int k,const std::string& filename);
    CComplexVector(const int k, const ComplexNumber *str);
    CComplexVector(const CComplexVector& k);
    void setdata();
    ~CComplexVector();
    /*const CComplexVector& operator +(const CComplexVector &k );
    const CComplexVector& operator -(const CComplexVector &k );
    const CComplexVector& operator *(const CComplexVector &k );*/
    CComplexVector& operator =(const CComplexVector &k );
    void out();
    virtual int output(const std::string& Filename)=0;
};
#endif // CCOMPLEXVECTOR_H

