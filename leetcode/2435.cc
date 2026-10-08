//矩阵中能被K整除的路径

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int numberOfPaths(vector<vector<int>>& grid, int k) {
    const int MOD=1e9+7;
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp(k,vector<int>(m*n,0));
    dp[grid[0][0]%k][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i-1>=0)
            for(int cnt=0;cnt<k;cnt++){
                dp[(cnt+grid[i][j])%k][i*n+j]=((long long)dp[(cnt+grid[i][j])%k][i*n+j]+dp[cnt][(i-1)*n+j])%MOD;
            }
            if(j-1>=0)
            for(int cnt=0;cnt<k;cnt++){
                dp[(cnt+grid[i][j])%k][i*n+j]=((long long)dp[(cnt+grid[i][j])%k][i*n+j]+dp[cnt][i*n+j-1])%MOD;
            }
        }
    }
    return dp[0][(m-1)*n+n-1];
}

int main()
{
    cout << "RIGHT!" << endl;
}