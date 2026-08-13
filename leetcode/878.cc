#include<iostream>
#include<numeric>
#include<cmath>
#include<vector>
using namespace std;

const int mod=1e9+7;

typedef long long LL;

int nthMagicalNumber(int n, int a, int b) { //二分，容斥
    int range=lcm(a,b);
    LL ans;
    for(LL l=0,r=(long long)n*min(a,b),m=0;l<=r;){
        m=(l+r)/2;
        if(m/a+m/b-m/range>=n){
            ans=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
    return static_cast<int>(ans%mod);
}

int main()
{
    cout << nthMagicalNumber(4,2,3);
    return 0;
}