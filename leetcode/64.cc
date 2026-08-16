//最小路径和

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;

const int MAXN=201;

int dp[MAXN*MAXN];


//记忆化搜索
int f1(const vector<vector<int>>& grid,int i,int j)
{
    if(i<0 || j<0) return INT_MAX;
    if(dp[i*MAXN+j]!=-1) return dp[i*MAXN+j];
    dp[i*MAXN+j]=grid[i][j]+min(f1(grid,i-1,j),f1(grid,i,j-1));
    return dp[i*MAXN+j];
}

int minPathSum1(vector<vector<int>>& grid) {
    memset(dp,-1,sizeof(dp));
    dp[0]=grid[0][0];
    return f1(grid,(int)grid.size()-1,(int)grid[0].size()-1);
}

// 严格位置依赖的动态规划 + 空间压缩技巧
int minPathSum2(vector<vector<int>>& grid) {
    int m=static_cast<int>(grid.size());
    int n=static_cast<int>(grid[0].size());
    vector<int> dp(n);
    dp[0]=grid[0][0];
    for(int j=1;j<n;j++) dp[j]=dp[j-1]+grid[0][j];
    for(int i=1;i<m;i++){
        dp[0]+=grid[i][0];
        for(int j=1;j<n;j++) dp[j]=grid[i][j]+min(dp[j],dp[j-1]);
    }
    return dp[n-1];
}