#include<iostream>
using namespace std;

int main(){
    int begin,end;
    cin>>begin>>end;
    int sum=0;
    for (int i=begin;i<=end;i++){
        sum+=i;
    }
    cout<<sum<<endl;
    return 0;
}