// 最长有效括号

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN=3e4+5;

int dp[MAXN];


int f(const string & s,int len,int i) //以i开头的最长有效括号长度
{
    if(dp[i]!=-1) return dp[i];
    int ans;
    if(s[i]==')' || i+1==len) ans=0;
    else if(s[i+1]==')') ans=f(s,len,i+2)+2;
    else{
        int next_len=f(s,len,i+1);
        if(i+next_len+1==len || s[i+next_len+1]=='(') ans=0;
        else ans=next_len+2+f(s,len,i+next_len+2); 
    }
    dp[i]=ans;
    return ans;
}

int longestValidParentheses1(string s) {
    memset(dp,-1,sizeof(dp));
    int len=static_cast<int>(s.length());
    dp[len]=0;
    int max_len=0;
    for(int i=0;i<len;i++) max_len=max(max_len,f(s,len,i));
    return max_len;
}

int longestValidParentheses2(string s) {
    //memset(dp,-1,sizeof(dp));
    int len=static_cast<int>(s.length());
    dp[len]=0;
    int max_len=0;
    for(int i=len-1;i>=0;i--){
        if(s[i]==')' || i+1==len) dp[i]=0;
        //else if(s[i+1]==')') dp[i]=dp[i+2]+2; 多余，已经包含在第三种情况里
        else{
            int next_len=dp[i+1];
            if(i+next_len+1==len || s[i+next_len+1]=='(') dp[i]=0;
            else dp[i]=next_len+2+dp[i+next_len+2]; 
        }
        max_len=max(max_len,dp[i]);
    }
    return max_len;
}