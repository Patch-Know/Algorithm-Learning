//矩阵中的最长递增路径

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN=200;

int dp[MAXN][MAXN];

bool check(const vector<vector<int>>& matrix,int cur,int i,int j)
{
    int m=static_cast<int>(matrix.size());
    int n=static_cast<int>(matrix[0].size());
    if(i>=0 && i<m && j>=0 && j<n && cur>matrix[i][j]) return true;
    return false;
}

int f(const vector<vector<int>>& matrix,int i,int j)
{
    if(dp[i][j]!=0) return dp[i][j];
    int ans=1,add=0;
    if(check(matrix,matrix[i][j],i+1,j)) add=max(add,f(matrix,i+1,j));
    if(check(matrix,matrix[i][j],i-1,j)) add=max(add,f(matrix,i-1,j));
    if(check(matrix,matrix[i][j],i,j+1)) add=max(add,f(matrix,i,j+1));
    if(check(matrix,matrix[i][j],i,j-1)) add=max(add,f(matrix,i,j-1));
    ans+=add;
    dp[i][j]=ans;
    return ans;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    memset(dp,0,sizeof(dp));
    int ans=0;
    int m=static_cast<int>(matrix.size());
    int n=static_cast<int>(matrix[0].size());
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ans=max(ans,f(matrix,i,j));
        }
    }
    return ans;
}