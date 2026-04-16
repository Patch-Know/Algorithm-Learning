#include<iostream>
#include<array>
using namespace std;

int main(){
    array<double,3> at;
    cout<<"Enter your scores(3 times): \n";
    cin>> at[0] >>at[1]>>at.at(2);
    cout<<"Average: "<<(at[0]+at[1]+at[2])/3<<endl;
    return 0;
}