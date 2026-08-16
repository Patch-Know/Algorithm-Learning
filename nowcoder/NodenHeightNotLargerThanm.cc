// 节点数为n高度不大于m的二叉树个数
// 现在有n个节点，计算出有多少个不同结构的二叉树
// 满足节点个数为n且树的高度不超过m的方案
// 因为答案很大，所以答案需要模上1000000007后输出

#include<iostream>
#include<cstring>
using namespace std;

const int MAXM=51;
const int MAXN=51;
const int MOD=1e9+7;

int dp[MAXN][MAXM];

int f1(int n,int m)
{
    if(n==0) return 1;
    if(m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    int ans=0;
    for(int k=0;k<n;k++){
        ans=(ans+(long long)f1(k,m-1)*f1(n-1-k,m-1)%MOD)%MOD;
    }
    dp[n][m]=ans;
    return ans;
}

//也能空间压缩哦嘿嘿！！

int dp2[MAXN];

int f2(int n,int m)
{
    dp2[0]=1;
    for(int i=1;i<=m;i++){
        for(int j=n;j>0;j--){
            dp2[j]=0;//记得初始化
            for(int k=0;k<j;k++){
                dp2[j]=(dp2[j]+(long long)dp2[k]*dp2[j-1-k]%MOD)%MOD;
            }
        }
    }
    return dp2[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //memset(dp,-1,sizeof(dp));
    int n,m;
    cin >> n >> m;
    //cout << f1(n,m);
    cout << f2(n,m);
    return 0;
}