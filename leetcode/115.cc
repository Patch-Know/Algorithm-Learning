//不同的子序列

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN=1001;

int dp[MAXN][MAXN];

int numDistinct1(string s, string t) {
    const int MOD=INT_MAX;
    memset(dp,-1,sizeof(dp));
    int m=static_cast<int>(s.length());
    int n=static_cast<int>(t.length());
    dp[0][0]=s[0]==t[0]?1:0;
    for(int i=1;i<m;i++){
        dp[i][0]=dp[i-1][0]+(s[i]==t[0]?1:0);
    }
    for(int j=1;j<n;j++){
        dp[0][j]=0;
        for(int i=1;i<m;i++){
            dp[i][j]=(dp[i-1][j]+(s[i]==t[j]?dp[i-1][j-1]:0))%MOD; //数太大，注意取模
        }
    }
    return dp[m-1][n-1];
}

int numDistinct2(string s, string t) {
    const int MOD=INT_MAX;
    int m=static_cast<int>(s.length());
    int n=static_cast<int>(t.length());
    vector<long long> dp(m,-1);
    dp[0]=s[0]==t[0]?1:0;
    for(int i=1;i<m;i++){
        dp[i]=dp[i-1]+(s[i]==t[0]?1:0);
    }
    for(int j=1,leftup,backup;j<n;j++){
        leftup=dp[0];
        dp[0]=0;
        for(int i=1;i<m;i++){
            backup=dp[i];
            dp[i]=(dp[i-1]+(s[i]==t[j]?leftup:0))%MOD; //数太大，注意取模
            leftup=backup;
        }
    }
    return dp[m-1];
}

//既然依赖上和左上，最好的方式是横着填
int numDistinct3(string s, string t) {
    const int MOD=INT_MAX;
    int m=static_cast<int>(s.length());
    int n=static_cast<int>(t.length());
    vector<long long> dp(n,0);
    dp[0]=s[0]==t[0]?1:0;
    for(int i=1;i<m;i++){
        for(int j=n-1;j>=1;j--){
            if(s[i]==t[j]){
                dp[j]=(dp[j]+dp[j-1])%MOD;
            }
        }
        if(s[i]==t[0]) dp[0]=(dp[0]+1)%MOD;
    }
    
    return dp[n-1];
}

int main()
{
    cout << numDistinct3("rabbbit","rabbit");
}