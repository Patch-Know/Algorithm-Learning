#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b,max=0,day;
    bool isUnhappy=false;
    for(int i=1;i<=7;i++){
        cin>>a>>b;
        if(a+b>8&&(isUnhappy==false||a+b>max)){
            max=a+b;
            day=i;
            isUnhappy=true;
        }
    } 
    if(isUnhappy) cout<<day;
    else cout<<"0";

    return 0;
}