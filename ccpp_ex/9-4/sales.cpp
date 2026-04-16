#include<iostream>
#include"sales.h"

static double average(double ar[],int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=ar[i];
    }
    return sum/n;
}

static double max(double ar[],int n)
{
    double max=ar[0];
    for (int i = 1; i < n; i++)
    {
        if (ar[i]>max) max=ar[i];
    }
    return max;
}

static double min(double ar[],int n)
{
    double min=ar[0];
    for (int i = 1; i < n; i++)
    {
        if (ar[i]<min) min=ar[i];
    }
    return min;
}

void SALES::setsales(sales & s,const double ar[],int n)
{
    if (n>=QUARTERS) n=QUARTERS;
    for (int i = 0; i < n; i++)
    {
        s.sales[i]=ar[i];
    }
    for (int i = n; i < QUARTERS; i++)
    {
        s.sales[i]=0.0;
    }
    s.average=average(s.sales,n);
    s.max=max(s.sales,n);
    s.min=min(s.sales,n);
}

void SALES::setsales(sales & s)
{
    for (int i = 0; i < QUARTERS; i++)
    {
        std::cout<<"Enter number#"<<i<<" : ";
        std::cin>>s.sales[i];
        while (getchar()!='\n') continue;
    }
    s.average=average(s.sales,QUARTERS);
    s.max=max(s.sales,QUARTERS);
    s.min=min(s.sales,QUARTERS);
}

void SALES::showsales(const sales & s)
{
    using std::endl;
    for (int i = 0; i < QUARTERS; i++)
    {
        std::cout<<"sales#"<<i<<" : "<<s.sales[i]<<endl;
    }
    std::cout<<"average: "<<s.average<<endl;
    std::cout<<"max: "<<s.max<<endl;
    std::cout<<"min: "<<s.min<<endl;
}
