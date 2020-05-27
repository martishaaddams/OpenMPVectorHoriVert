#include "complexvector.hpp"
#include"complexnumber.h"
CComplexVector::CComplexVector()
{
    n=0;
}
CComplexVector::CComplexVector(const int k)
{
        n=k;
        arr.resize(k);

}
CComplexVector::CComplexVector(const int k, const ComplexNumber *str)
{
    n=k;
    arr.resize(k);
    for(int i=0;i<n;i++)
    {
        arr[i]=str[i];
    }
}
CComplexVector::CComplexVector(const CComplexVector& k)
{
    n=k.n;
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        arr[i]=k.arr[i];
    }

}
CComplexVector::~CComplexVector()
{

    //std::cout<<"destructor worked"<<endl;
}
CComplexVector::CComplexVector(const int k,const std::string& filename)
{
    n=k;
    arr.resize(k);
    Filename=filename;

}

/*const CComplexVector& CComplexVector::operator +(const CComplexVector &k)
{
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i]+k.arr[i];
    }
    return *this;
}
const CComplexVector& CComplexVector::operator -(const CComplexVector &k)
{
    CComplexVector *z;
    z=new CComplexVector;
    z->n=n;
    for(int i=0;i<n;i++)
    {
        z->arr[i]=arr[i]-k.arr[i];
    }
    return z;
}
const CComplexVector& CComplexVector::operator *(const CComplexVector &k)
{
    for(int i=0;i<n;i++)
    {
        arr[i].outp();
        cout<<" ";
        arr[i]=arr[i]*k.arr[i];
        arr[i].outp();
        cout<<endl;
    }
    return *this;
}*/
CComplexVector& CComplexVector::operator =(const CComplexVector &k)
{
    n=k.n;
    //delete arr;
    arr.resize(n);
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
#pragma omp parallel for
    for(int i=0;i<n;i++)
    {
        arr[i]=k.arr[i];
    }
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    cout << "ComplexVector parallel " << elapsed_ms << endl;
   // cout<<"basic"<<endl;
    return *this;
}
void CComplexVector::out()
{
    for(int i=0;i<n;i++)
    {
        arr[i].outp();
        if(i+1<n)std::cout<<",";

    }
    std::cout<<endl;
}
void CComplexVector::setdata()
    {
        for (int i=0;i<n;i++)
        {
            cin>>arr[i].a;
            cin>>arr[i].b;
        }
    }



