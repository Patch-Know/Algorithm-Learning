//爱吃香蕉的珂珂

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

ll f(const vector<int>& piles, int speed)
{
    int len=static_cast<int>(piles.size());
    ll hour=0;
    for(auto x:piles) hour+=(x+speed-1)/speed; //算需要的小时数更省时间
    return hour;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int max_k;
    for(auto x:piles) max_k=max(max_k,x);
    int l=1,r=max_k;
    int ans;
    while(l<=r){
        int m=(l+r)/2;
        if(f(piles,m)<=h){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    return ans;
}