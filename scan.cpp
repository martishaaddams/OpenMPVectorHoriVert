#ifndef SCAN
#define SCAN
#include"omp.h"
#include<fstream>
#include<map>
#include<chrono>
#include "complexvector.hpp"
#include "complexvector1.hpp"
#include "complexvector0.hpp"
#include"factory.h"
#include"factoryhori.h"
#include"factoryvirt.h"
void scan(const std::string& inp)
{
    factoryhori* hori=new factoryhori;
    factoryvirt* vert=new factoryvirt;
    ifstream in;
    in.open(inp);
    int n;
    std::string c;
    std::string out;
    std::vector<CComplexVector*> arr;
    std::vector<CComplexVector*>::iterator it;
    std::map<std::string, factory*> mp;
    mp.insert(std::make_pair("Hori",hori));
    mp.insert(std::make_pair("Vert",vert));
    if(!in.is_open())
        cout<<"Something went wrong, there is no such file: "<<inp;
    else
    {
        while(in>>c)
        {
            if(mp.find(c)!=mp.end())
            {


                arr.resize(arr.size()+1);
                if(arr.size()==1)
                    it=arr.begin();
                else
                    it=--arr.end();
                in>>out;
                in>>n;
                //if(c==0)
                //{
                    //cout<<c;


                    (*it)=mp[c]->create(n,out);
                    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
                    //auto start = std::chrono::steady_clock::now();
                    #pragma omp parallel for
                    for (int k=0;k<n;k++)
                    {
                        in>>(*it)->arr[k].a;
                        in>>(*it)->arr[k].b;
                    }
                    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
                    //auto end= std::chrono::steady_clock::now();
                    //std::chrono::duration<double> seconds = end - start;
                    int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
                    cout << elapsed_ms << endl;
                }

                else
                {
                    cout<<"Wrong data,retry"<<endl;

                }


        }
        in.close();
        for(it=arr.begin();it!=arr.end();++it)
        {

            (*it)->output((*it)->Filename);


        }
        for(it=arr.begin();it!=arr.end();++it)
        {
           delete *it;
        }

    }
}



#endif
