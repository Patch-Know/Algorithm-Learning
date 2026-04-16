#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[3];
    char b[3];
    cin>>a[0]>>a[1]>>a[2];
    cin>>b[0]>>b[1]>>b[2];
    sort(a,a+3);
    cout<<a[b[0]-'A']<<" "<<a[b[1]-'A']<<" "<<a[b[2]-'A'];
    return 0;
}