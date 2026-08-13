//斐波那契数

#include<iostream>
#include<cstring>

using namespace std;

int dp[32];

int f1(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    int ans=f1(n-1)+f1(n-2);
    dp[n]=ans;
    return ans;
}

int fib1(int n) {
    memset(dp,-1,sizeof(dp));
    return f1(n);
}

int fib2(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int fib3(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int lastlast=0,last=1;
    for(int i=2,cur;i<=n;i++){
        cur=lastlast+last;
        lastlast=last;
        last=cur;
    }
    return last;
}

int main()
{
    cout << fib3(10);
    return 0;
}