#ifndef FACTORYHORI_H
#define FACTORYHORI_H
#include"complexvector.hpp"
#include"complexnumber.h"
#include"complexvector1.hpp"
#include"complexvector0.hpp"
#include"factory.h"
class factoryhori:public factory
{
    public:
    CComplexVector* create(int n,const std::string& filename)const
    {
     return new CComplexVector0(n,filename);
    }
    //~factoryhori(){};
};
#endif
