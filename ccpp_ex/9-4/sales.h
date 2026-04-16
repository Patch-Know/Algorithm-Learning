#ifndef SALES_H_
#define SALES_H_
namespace SALES
{
    const int QUARTERS = 4;
    struct sales
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };

    void setsales(sales & s,const double ar[],int n);

    void setsales(sales & s);

    void showsales(const sales & s);


       
} // namespace SALES

#endif