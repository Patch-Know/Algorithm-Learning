#include<iostream>
#include<vector>

using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> ans(n);
    vector<int> cnt(n+2,0);
    for(auto & v:bookings){ //注意是1到n进行编号
        cnt[v[0]]+=v[2];
        cnt[v[1]+1]-=v[2];
    }
    for(int i=1;i<n+2;i++) cnt[i]+=cnt[i-1];
    for(int i=0;i<n;i++) ans[i]+=cnt[i+1];
    return ans;
}