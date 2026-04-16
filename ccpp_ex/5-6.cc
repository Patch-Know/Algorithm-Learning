#include<iostream>
#include<string>
using namespace std;

int main(){
    const int Month_num=12,Year_num=3;
    int sale[Year_num][Month_num];
    int sum[Year_num]{0};
    string month[Month_num]{"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
    for(int j=0;j<Year_num;j++){
        for (int i=0;i<Month_num;i++)
        {
            cout<<"Enter the sales in "<<month[i]<<"(Year"<<j+1<<"): ";
            cin>>sale[j][i];
            sum[j]+=sale[j][i];
        }
    }
    cout<<"The sales of three years:\n" << sum[0]<<endl << sum[1]<<endl <<sum[2] <<endl;
    return 0;
}