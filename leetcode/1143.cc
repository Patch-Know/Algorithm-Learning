//最长公共子序列

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