#include<iostream>
#include<functional>

using namespace std;
using namespace std::placeholders;

int f1(int a,int b)
{
    return a+b;
}

int f2(int a,int b,int c)
{
    return a+b+c;
}

struct m
{
    int operator()(int a,int b){return a-b;}
};


int receive(function<int(int,int)> f,int a,int b)
{
    return f(a,b);
}

int main()
{
    function<int(int,int)> a1 = f1;
    decltype(f1) * pf1 = f1;
    function<int(int,int)> a2 = pf1;
    function<int(int,int)> a3 = [](int a,int b){return a*b;};
    auto bf = bind(f2,_1,_2,5);
    function<int(int,int)> a4 = bf;
    function<int(int,int)> a5 = m();
    //cout << a5(1,2) << endl;
    cout << receive(m(),1,2) << endl;

    return 0;
}