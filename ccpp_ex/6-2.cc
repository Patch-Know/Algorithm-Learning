#include<iostream>
using namespace std;

int main()
{
    const int Max=10;
    double donation[Max];
    int cnt=0,overcnt=0;
    double input,sum;
    while (cnt<Max && cin>>input){
        donation[cnt]=input;
        sum+=input;
        cnt++;
    }
    double ave=sum/cnt;
    for (int i=0;i<cnt;i++){
        if(donation[i]>ave) overcnt++;
    }
    cout<<"Average: "<<ave<<endl;
    cout<<"Over ave: "<<overcnt<<endl;
    return 0;
}