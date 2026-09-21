#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int max_len=0;
    int ret_l=0,ret_r=0;
    int l=0,r=0;
    while(r<n){
        if(r>0 && v[r-1]>=v[r]) l=r;
        if(r-l+1>max_len){
            max_len=r-l+1;
            ret_l=l;
            ret_r=r;
        }
        r++;
    }
    for(int i=ret_l;i<=ret_r;i++){
        cout << v[i];
        if(i<ret_r) cout << ' ';
    }
}