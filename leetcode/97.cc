//交错字符串

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

const int MAXN=101;

int dp[MAXN][MAXN];

bool isInterleave1(string s1, string s2, string s3) {
    memset(dp,0,sizeof(dp));
    int m=static_cast<int>(s1.length());
    int n=static_cast<int>(s2.length());
    int len=static_cast<int>(s3.length());
    if(m+n!=len) return false;
    dp[0][0]=1;
    for(int k=1;k<=len;k++){
        for(int i=0,j=k-1;j>=0;i++,j--){
            if(i<=m && j<=n && dp[i][j]){
                if(i+1<=m && s1[i]==s3[k-1]) dp[i+1][j]=1;
                if(j+1<=n && s2[j]==s3[k-1]) dp[i][j+1]=1;
            }
        }
    }
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n;j++) cout << dp[i][j];
    //     cout << '\n';
    // }
    return dp[m][n];
}

//其实也是依赖左和上，可以空间压缩
bool isInterleave2(string s1, string s2, string s3) {
    int m=static_cast<int>(s1.length());
    int n=static_cast<int>(s2.length());
    int len=static_cast<int>(s3.length());
    if(m+n!=len) return false;
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int j=1;j<=n;j++){
        if(dp[j-1] && s2[j-1]==s3[j-1]) dp[j]=1;
    }
    for(int i=1;i<=m;i++){
        dp[0]=(dp[0] && s1[i-1]==s3[i-1])?1:0;
        for(int j=1;j<=n;j++){
            dp[j]=((dp[j-1] && s2[j-1]==s3[i+j-1])
             ||(dp[j] && s1[i-1]==s3[i+j-1]))?1:0;
        }
    }
    return dp[n];
}

int main()
{
    cout << isInterleave2("aabcc","dbbca","aadbbcbcac");
    return 0;
}