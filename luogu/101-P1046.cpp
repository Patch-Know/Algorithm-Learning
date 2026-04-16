#include<bits/stdc++.h>

using namespace std;

int main(){
    int h;
    int sum=0;
    int apple[10];
    for(int i=0;i<10;i++){
        cin >> apple[i];
    }
    cin>>h;
    int fh=h+30;
    for(int i=0;i<10;i++){
        if(fh>=apple[i]) sum++;
    }
    cout<<sum;
    return 0;
}