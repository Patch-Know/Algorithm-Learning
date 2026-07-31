#include<iostream>

using namespace std;

int & f(int a,int b);

int a;
int main()
{
 int m, n;
 cin >> m >> n;
 int &x=f(m,n);
 x*=2;
 cout<<a;
 return 0;
}

int & f(int a,int b)
{
    ::a=a+b;
    return ::a;
}