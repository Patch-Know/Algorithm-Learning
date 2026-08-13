//解码方法

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<limits.h>
#include<algorithm>
using namespace std;

const int MAXN=101;

int dp[MAXN];

int f(const string & s,int i,int len)
{
    if(i==len) return 1; //说明前面可以正确解码
    if(s[i]=='0') return 0;
    if(dp[i]!=-1) return dp[i];
    int ans=0;
    ans+=f(s,i+1,len);
    if(i+1<len && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6' ) )) ans+=f(s,i+2,len);
    dp[i]=ans;
    return ans;
}

int numDecodings1(string s) {
    memset(dp,-1,sizeof(dp));
    return f(s,0,static_cast<int>(s.length()));
}

int numDecodings3(string s) {
    int n=static_cast<int>(s.length());
    int next=s[n-1]=='0'?0 : 1 ,nextnext=1;
    for(int i=n-2,cur;i>=0;i--){
        if(s[i]=='0') cur=0;
        else{
            cur=next;
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6' )) cur+=nextnext;
        }
        nextnext=next;
        next=cur;
    }
    return next;
}