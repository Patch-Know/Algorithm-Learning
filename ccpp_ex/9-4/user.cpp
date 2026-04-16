#include<iostream>
#include"sales.h"
int main()
{
    using namespace SALES;
    sales v1,v2;
    double temp[3]{4.6,3.2,7.1};
    setsales(v1,temp,3);
    setsales(v2);
    std::cout<<"\nv1:\n";
    showsales(v1);
    std::cout<<"\nv2:\n";
    showsales(v2);   
    return 0;
}