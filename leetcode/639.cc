//解码方法II

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<limits.h>
#include<algorithm>
using namespace std;

typedef long long ll;

const int MAXN=1e5+1;
const ll mod=1e9+7;
ll dp[MAXN];

ll f(const string & s,int i,int len)
{
    if(i==len) return 1; //说明前面可以正确解码
    if(s[i]=='0') return 0;
    if(dp[i]!=-1) return dp[i];
    ll ans=(s[i]=='*'? 9 : 1)*f(s,i+1,len)%mod;
    if(i+1<len){
        if((s[i]=='1' && s[i+1]!='*') || (s[i]=='2' && s[i+1]>='0' && s[i+1]<='6' ) ) ans=(ans+f(s,i+2,len))%mod;
        else if(s[i]=='1' && s[i+1]=='*') ans=(ans+9*f(s,i+2,len))%mod;
        else if(s[i]=='2' && s[i+1]=='*') ans=(ans+6*f(s,i+2,len))%mod;
        else if(s[i]=='*' && s[i+1]=='*') ans=(ans+15*f(s,i+2,len))%mod;
        else if(s[i]=='*' && s[i+1]<='6') ans=(ans+2*f(s,i+2,len))%mod;
        else if(s[i]=='*') ans=(ans+f(s,i+2,len))%mod;
    }
    dp[i]=ans;
    return ans;
}

int numDecodings(string s) {
    memset(dp,-1,sizeof(dp));
    return f(s,0,static_cast<int>(s.length()));
}

