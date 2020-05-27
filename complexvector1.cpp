#include"complexvector1.hpp"
#include<chrono>
//#define PARALLEL
const CComplexVector1 CComplexVector1::operator +(const CComplexVector1& k)
{
    CComplexVector1 z(k.n);
   // z.out();
    //cout<<endl;

    if ((this->op == "with") || (k.op == "with"))
        cout << "omp" << endl;
    else
        cout << "no omp" << endl;
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    if((this->op=="with")||(k.op=="with"))
#pragma omp parallel for

    for(int i=0;i<n;i++)
    {
        z.arr[i]=arr[i]+k.arr[i];
        //z.arr[i].outp();
        //cout<<endl;
    }
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    cout << "ComplexVector1 parallel " << elapsed_ms << endl;
    return z;
}
const CComplexVector1 CComplexVector1::operator -(const CComplexVector1 &k)
{
    CComplexVector1 z(n);
    if ((this->op == "with") || (k.op == "with"))
        cout << "omp" << endl;
    else
        cout << "no omp" << endl;
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    if((this->op=="with")||(k.op=="with"))
#pragma omp parallel for
    for(int i=0;i<n;i++)
    {
        z.arr[i]=arr[i]-k.arr[i];
    }
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    cout << "ComplexVector1 parallel " << elapsed_ms << endl;
    return z;
}
const CComplexVector1 CComplexVector1::operator *(const CComplexVector1 &k)
{
     CComplexVector1 z(n);
if ((this->op == "with") || (k.op == "with"))
        cout << "omp" << endl;
    else
        cout << "no omp" << endl;
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    if((this->op=="with")||(k.op=="with"))
#pragma omp parallel for
    for(int i=0;i<n;i++)
    {
        z.arr[i]=arr[i]*k.arr[i];

    }
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    cout << "ComplexVector1 parallel " << elapsed_ms << endl;
    return z;
}
/*CComplexVector1& CComplexVector1::operator =(const CComplexVector1 &k)
{
    n=k.n;
    delete arr;
    arr=new ComplexNumber [n];
    for(int i=0;i<n;i++)
    {
        arr[i]=k.arr[i];
    }
   // cout<<"basic"<<endl;
    return *this;
}*/
int CComplexVector1::output(const std::string& Filename)
{

    //FILE *o=stdout;
    //freopen(Filename,"a",stdout);
    ofstream fout(Filename,ios_base::app);
    if(!fout.is_open()){
        cout<<"Something went wrong,there is no such file: "<<Filename;
        return -1;
        }
    else
    { fout<<"(";
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
#pragma omp parallel for
        for(int i=0;i<n;i++)
        {
             fout<<arr[i].a;
             fout<<"+";
             fout<<"i*";
             fout<<arr[i].b;
             if(i!=n-1)fout<<endl;
        }
        std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
        int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
        fout<<")";
        cout << "ComplexVector1 parallel " << elapsed_ms << endl;
        fout<<endl;
        fout<<endl;
        fout.close();
         return 0;
    }
    //fclose(stdout);
    //freopen("CON","a",stdout);
    //stdout = fdopen(0, "w");
    //printf("dupa2");
    //*stdout=*o;




}
