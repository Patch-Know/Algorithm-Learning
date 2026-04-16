#include<iostream>
#include<array>
using namespace std;

int main(){
    array<long double,101> aj;
    aj[1]=aj[0]=1.0L;//long double+'L'
    for (int i=2;i<101;i++)
        aj[i]=i*aj[i-1];
    cout<<aj[100];
    return 0;
}