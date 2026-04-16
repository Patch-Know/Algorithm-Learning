#include<iostream>

double thav(double a,double b)
{
    return 2.0*a*b/(a+b);
}

int main()
{
    using namespace std;
    double x,y;
    cout<<"Enter 2 numbers(0 to quit):";
    while (cin>>x>>y && x!=0 &&y!=0){
        cout<<"average(th): "<<thav(x,y)<<endl;
    }
    return 0;
}