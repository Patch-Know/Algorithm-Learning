#include<iostream>
#include<string>
using namespace std;

int main(){
    const int Month_num=12;
    int sale[Month_num];
    int sum=0;
    string month[Month_num]{"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
    for (int i=0;i<Month_num;i++)
    {
        cout<<"Enter the sales in "<<month[i]<<": ";
        cin>>sale[i];
        sum+=sale[i];
    }
    cout<<"The sales of this year: " << sum <<endl;
    return 0;
}