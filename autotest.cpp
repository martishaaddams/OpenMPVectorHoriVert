#ifndef AUTOTEST
#define AUTOTEST
#include "complexvector.hpp"
#include "complexvector1.hpp"
#include "complexvector0.hpp"
int autotest()
{
    cout<<"TEST1:";
    int c=0;
    int a[6];
    int b[6];
    a[0]=0;
    a[1]=1;
    a[2]=2;
    a[3]=3;
    a[4]=4;
    a[5]=5;
    b[0]=9;
    b[1]=1;
    b[2]=2;
    b[3]=3;
    b[4]=4;
    b[5]=5;
    CComplexVector0 m (3);
    CComplexVector0 n (3);
    for(int i=0;i<3;i++)
    {
        m.arr[i].a=a[i];
        m.arr[i].b=a[i+1];
    }
    for(int i=0;i<3;i++)
    {
        n.arr[i].a=b[i];
        n.arr[i].b=b[i+1];
    }
    CComplexVector0 k(3);
    k=m+n;
    for(int i=0;i<3;i++)
    {
        //k.out();
        if(!((k.arr[i].a==a[i]+b[i])&&(k.arr[i].b==a[i+1]+b[i+1])))
        c++;

    }
    if(c==0) cout<<"OK"<<endl;
    else cout<<"NO"<<endl;
    cout<<"TEST2:";
    CComplexVector1 w(1);
    CComplexVector1 h(1);
    w.arr[0].a=1;
    w.arr[0].b=2;
    h.arr[0].a=1;
    h.arr[0].b=2;
    CComplexVector1 area(w*h);
    if((area.arr[0].a==-3)&&(area.arr[0].b==4))
        cout<<" OK"<<endl;
    else
    {
        cout<<" NO"<<endl;
        c++;
    }
    cout<<"TEST3:";
    area=w-h;
    //area.out();
    //w.out();
    //h.out();
    if((area.arr[0].a==0)&&(area.arr[0].b==0))
        cout<<" OK"<<endl;
    else
    {
        cout<<" NO"<<endl;
        c++;
    }
    return c;
}
#endif
