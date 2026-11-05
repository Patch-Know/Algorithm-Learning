//how many turns?
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i=0;i<N;i++) cin >> v[i];
    vector<pair<int,int>> st(N);
    int r=0;
    for(int i=N-1;i>=0;i--){
        int cnt=0;
        while(r>0 && v[i]>st[r-1].first){
            cnt=max(st[--r].second,cnt+1);
        }
        st[r++]={v[i],cnt};
    }
    int max_num=st[0].second;
    for(int i=1;i<r;i++){
        max_num=max(max_num,st[i].second);
    }
    cout << max_num;
}
