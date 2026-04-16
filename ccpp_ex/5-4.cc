#include<iostream>
using namespace std;

int main(){
    int year=0;
    double da,cl,begin=100.0;
    da=cl=begin;
    while (da>=cl)
    {
        year+=1;
        da+=begin*0.10;
        cl*=1.05;
    }
    cout<<year<<endl;
    
    return 0;
}