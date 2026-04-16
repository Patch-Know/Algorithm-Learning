#include<iostream>
#include<stdio.h>

using namespace std;

double RoundUp(double N,int DecPlaces);
void PrintFractionPart(double FractionPart,int DecPlaces);
void PrintReal(double N,int DecPlaces);
void PrintDight(int digit) //打印一位数字
{
    printf("%d",digit%10);
}
int IntPart(double N) //提取整数部分
{
    return (int)N;
}
double DecPart(double N) //提取小数部分
{
    return N-IntPart(N);
}

void 
PrintOut(unsigned int N) //递归打印无符号整数
{
    if(N>10){
        PrintOut(N/10);
    }
    PrintDight(N%10);
}

int main()
{
    double PI=3.1415926535;
    PrintReal(PI,9);

    return 0;
}

double RoundUp(double N,int DecPlaces) //将N根据小数精度进位
{
    double AmountToAdd = 0.5;
    for(int i=0;i<DecPlaces;i++){
        AmountToAdd/=10;
    }
    return N+AmountToAdd;
}
void PrintFractionPart(double FractionPart,int DecPlaces)//将小数部分根据小数位数打印
{
    int Adigit;
    for(int i=0;i<DecPlaces;i++){
        FractionPart*=10;
        Adigit=IntPart(FractionPart);
        PrintDight(Adigit);
        FractionPart=DecPart(FractionPart);
    }
}
void PrintReal(double N,int DecPlaces) //根据小数精度打印实数
{
    int IntegerPart;
    double FractionPart;

    if(N<0){
        putchar('-');
        N=-N;
    }
    N=RoundUp(N,DecPlaces);
    IntegerPart=IntPart(N);
    FractionPart=DecPart(N);
    PrintOut(IntegerPart);
    if(DecPlaces>0)
    putchar('.');
    PrintFractionPart(FractionPart,DecPlaces);
}