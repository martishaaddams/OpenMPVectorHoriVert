#ifndef FACTORY_H
#define FACTORY_H
#include"complexvector.hpp"
#include"complexnumber.h"
#include"complexvector1.hpp"
#include"complexvector0.hpp"
class factory
{
    public:
    virtual CComplexVector* create(int n,const std::string& filename) const=0;
    //virtual ~factory() {};
};
#endif
