//同时运行N台电脑的最长时间
//碎片拼接法

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

bool f(const vector<int>& batteries,ll n,ll minute)
{
    ll sum=0;
    for(ll x:batteries) x<minute?sum+=x:n--;
    if(sum>=n*minute) return true;
    return false;
}

ll maxRunTime(int n, vector<int>& batteries) {
    ll l=0,r=0,sum=0,maxi=0;
    for(ll x:batteries){
        sum+=x;maxi=max(maxi,x);
    }
    if(sum>=n*maxi) return sum/n;
    r=maxi-1;
    ll ans;
    while(l<=r){
        ll m=(l+r)/2;
        if(f(batteries,n,m)){
            ans=m;
            l=m+1;
        }else r=m-1;
    }
    return ans;
}