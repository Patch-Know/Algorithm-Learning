//环绕字符串中唯一的子字符串

#include<iostream>
#include<vector>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

const int MAXN=1e5+5;

int dp[MAXN];

int cnts[26];

int findSubstringInWraproundString(string s) {
    memset(dp,0,sizeof(dp));
    memset(cnts,0,sizeof(cnts));
    int len=static_cast<int>(s.length());
    dp[len]=0;
    for(int i=len-1;i>=0;i--){
        dp[i]=(i+1==len || s[i+1]!='a'+(s[i]-'a'+1)%26)? 1 : 1+dp[i+1];
        cnts[s[i]-'a']=max(cnts[s[i]-'a'],dp[i]);
    }
    int ans=0;
    for(int i=0;i<26;i++){
        ans+=cnts[i];
    }
    return ans;
}