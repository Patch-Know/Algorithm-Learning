//等位or完成旅途的最少时间

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

ll f(const vector<int>& time,ll limit)
{
    ll ans=0;
    for(ll x:time) ans+=limit/x;
    return ans;
}

ll minimumTime(vector<int>& time, int totalTrips) {
    ll l=1,r,mini=1e7+5,ans=0;
    for(ll x:time) mini=min(mini,x);
    r=mini*totalTrips;
    while(l<=r){
        ll m=(l+r)/2;
        if(f(time,m)>=totalTrips){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    return ans;
}