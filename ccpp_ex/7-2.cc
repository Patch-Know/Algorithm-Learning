#include<iostream>
#include<stdlib.h>
using namespace std;
void show(const double* pa,int n);
int input(double* pa);
double average(const double*pa,int n);

int main()
{
    double ball[10]{0};
    int cnt=input(ball);
    show(ball,cnt);
    return 0;
}

int input(double* pa)
{
    int i=0;
    cout<<"Enter a score: ";
    while(i<10 && cin>>pa[i]){
        i++;
        cout<<"Enter a score: ";
    }
    cin.clear();
    while (getchar()!='\n') continue;
    return i;
}

void show(const double* pa,int n)
{
    if (n==0){
        printf("No score.");
        exit(EXIT_SUCCESS);
    }
    for (int i=0;i<n;i++){
        cout<<pa[i]<<" ";
    }
    cout<<endl<<average(pa,n)<<endl;
}

double average(const double*pa,int n)
{
    double sum=0;
    for (int i=0;i<n;i++){
        sum+=pa[i];
    }
    return sum/n;
}