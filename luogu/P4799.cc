//Ice Hockey World Championship
//大数字记得开long long!!!
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

void bfs(vector<ll> &res,const vector<ll> &price,int i,int n,ll cost,ll limit)
{
    if(cost>limit) return;
    if(i==n){
        res.push_back(cost);
        return;
    }
    bfs(res,price,i+1,n,cost,limit);
    bfs(res,price,i+1,n,cost+price[i],limit);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    ll M;
    cin >> N >> M;
    vector<ll> price(N); //数字比较大
    vector<ll> l_arr,r_arr;
    for(int i=0;i<N;i++){
        cin >> price[i];
    }
    bfs(l_arr,price,0,N/2,0,M);
    bfs(r_arr,price,N/2,N,0,M);
    sort(l_arr.begin(),l_arr.end());
    sort(r_arr.begin(),r_arr.end());
    ll l=0,r=r_arr.size()-1;
    ll len=l_arr.size();
    ll ans=0;//数字比较大
    while(l<len){
        while(l_arr[l]+r_arr[r]>M) r--;
        ans+=(ll)r+1;
        l++;
    }
    cout << ans;
}