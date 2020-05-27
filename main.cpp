#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include"complexvector.hpp"
#include"complexnumber.h"
#include"complexvector1.hpp"
#include"complexvector0.hpp"
#include"factory.h"
#include"factoryhori.h"
#include"factoryvirt.h"
//#define PARALLEL
int autotest();
void scan(const std::string& inp);
int main(void)
{
    std::cout<<"begin"<<endl;
    ofstream lout("my.txt");
    if(!lout.is_open())
        cout<<"There is no my.txt";
    lout.close();
    lout.open("your.txt");
    if(!lout.is_open())
        cout<<"There is no your.txt";
    lout.close();

    //scan("data.txt");
    //cout<<autotest();
    int a[2];
    int b[2];
    a[0] = 1;
    a[1] = 2;
    b[0] = 4;
    b[1] = 5;
    CComplexVector1 m(10000000);
    CComplexVector1 n(10000000);
    for (int i = 0; i < m.n; i++)
    {
        m.arr[i].a = a[0];
        m.arr[i].b = a[1];
    }
    for (int i = 0; i < n.n; i++)
    {
        n.arr[i].a = b[0];
        n.arr[i].b = b[1];
    }
    m + n;
    m.op = "without";
    n.op = "without";
    m + n;

    //m + n;

    /*CComplexVector1 m;
    cout<<"hey,16"<<endl;
    m=a+b;
    m.out();
    CComplexVector0 k(a);
    CComplexVector0 l(b);
    m.output("your.txt");
    cout<<"hey,16"<<endl;
    CComplexVector0 n;
    n=k*a;
    k.out();
    n.output("my.txt");*/


    return 0;
}
