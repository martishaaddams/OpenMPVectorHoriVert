#ifndef FACTORYVIRT_H
#define FACTORYVIRT_H
#include"complexvector.hpp"
#include"complexnumber.h"
#include"complexvector1.hpp"
#include"complexvector0.hpp"
#include"factory.h"
class factoryvirt:public factory
{
    public:
    CComplexVector* create(int n,const std::string& filename)const
    {
        return new CComplexVector1(n,filename);
    }
    //~factoryvirt(){};
};
#endif
