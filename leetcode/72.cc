//编辑距离

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int minDistance(string word1, string word2) {
    int a=1,b=1,c=1;//插入，删除和替换的代价
    int m=static_cast<int>(word1.length());
    int n=static_cast<int>(word2.length());
    vector<int> dp(n+1,0);
    for(int j=1;j<=n;j++){
        dp[j]=dp[j-1]+a;
    }
    for(int i=1,leftup,backup;i<=m;i++){
        leftup=dp[0];
        dp[0]+=b;
        for(int j=1;j<=n;j++){
            backup=dp[j];
            //dp[j]=min(leftup+(word1[i-1]==word2[j-1]?0:c),min(dp[j]+b,dp[j-1]+a));
            //枚举优化
            dp[j]=word1[i-1]==word2[j-1]?leftup:min(leftup+c,min(dp[j]+b,dp[j-1]+a));
            leftup=backup;
        }
    }
    return dp[n];
}

int main()
{
    cout << minDistance("intention","execution");
    return 0;
}