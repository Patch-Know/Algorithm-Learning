//三步必杀

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef unsigned long long ull; //注意数据范围！！

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ull N,M;
    cin >> N >> M;
    vector<ull> set(N+3,0);
    for(ull i=0,l,r,s,e,d;i<M;i++){
        cin >> l >> r >> s >> e;
        d=(e-s)/(r-l);
        set[l]+=s;         //关键四步
        set[l+1]+=d-s;
        set[r+1]-=d+e;
        set[r+2]+=e;
    }
    for(ull i=1;i<=N;i++){
        set[i]+=set[i-1];
    }
    for(ull i=1;i<=N;i++){
        set[i]+=set[i-1];
    }
    ull xr=set[1];
    ull max=set[1];
    for(ull i=2;i<=N;i++){
        xr^=set[i];
        max=std::max(max,set[i]);
    }
    cout << xr << ' ' << max;
    return 0;
}