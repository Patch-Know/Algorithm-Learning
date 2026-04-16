#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,n,s=0;
    cin>>x>>n;
    for(int i=x;i<x+n;i++){
        if(i%7==0||i%7==6)continue;
        s+=250;
    }
    cout<<s;
    return 0;
}