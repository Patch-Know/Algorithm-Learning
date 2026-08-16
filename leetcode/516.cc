//最长回文子序列

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;


//严格位置依赖+空间压缩（借助辅助变量）
int longestCommonSubsequence(string text1, string text2) {
    int m=static_cast<int>(text1.length());
    int n=static_cast<int>(text2.length());
    vector<int> dp(n);
    dp[0]=text1[0]==text2[0]?1:0;
    for(int j=1;j<n;j++) dp[j]=text1[0]==text2[j]?1:dp[j-1];
    for(int i=1;i<m;i++){
        int leftup=dp[0];
        dp[0]=text1[i]==text2[0]?1:dp[0];
        for(int j=1;j<n;j++){
            int rightdown=text1[i]==text2[j]?(leftup+1):leftup;
            leftup=dp[j];
            dp[j]=max(rightdown,max(dp[j-1],dp[j]));
        }
    }
    return dp[n-1];
}

int longestPalindromeSubseq1(string s) {
    string r=s;
    reverse(r.begin(),r.end());
    return longestCommonSubsequence(s,r);
}

//也可以用区间dp做
const int MAXN=1000;

int dp[MAXN][MAXN];

int f(const string & s,int l,int r)
{
    if(dp[l][r]!=0) return dp[l][r];
    int ans=0;
    if(l==r) ans=1;
    else if(l+1==r) ans=s[l]==s[r]?2:1;
    else if(s[l]==s[r]) ans=f(s,l+1,r-1)+2;
    else ans=max(f(s,l,r-1),f(s,l+1,r));
    dp[l][r]=ans;
    return ans;
}

int longestPalindromeSubseq2(string s) {
    memset(dp,0,sizeof(dp));
    return f(s,0,int(s.length())-1);
}

//严格位置依赖+空间压缩（其实画图很好理解的）
int longestPalindromeSubseq3(string s) {
    int n=static_cast<int>(s.length());
    vector<int> dp(n);
    for(int l=n-1,leftdown=0,backup;l>=0;l--){
        dp[l]=1; //dp[l][l]
        if(l+1<n){
            leftdown=dp[l+1]; 
            dp[l+1]=s[l]==s[l+1]?2:1;//dp[l][l+1]
        }
        for(int r=l+2;r<n;r++){
            backup=dp[r];
            if(s[l]==s[r]) dp[r]=leftdown+2;//dp[l+1][r-1]+2
            else dp[r]=max(dp[r-1],dp[r]);//max(dp[l][r-1],dp[l+1][r])
            leftdown=backup;
        }
    }
    return dp[n-1];//dp[0][n-1]
}


int main()
{
    cout << longestPalindromeSubseq2("aa");
}