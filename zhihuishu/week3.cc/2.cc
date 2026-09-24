//remove_k(int i, int k)

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v(10);
    int cnt=10;
    for(int &num:v) num=cnt--;
    int i,k;
    cin >> i >> k;
    if(i<1 || i>10 || k<=0 || i+k-1>10){
        cout << "error";
        return 0;
    }
    if(i==1 && k==10){
        v.clear();
        cout << "empty";
        return 0;
    }
    int pos=i-1;
    for(int j=i+k-1;j<10;j++){
        v[pos++]=v[j];
    }
    for(int i=0;i<pos;i++){
        cout << v[i] << ' ';
    }
}