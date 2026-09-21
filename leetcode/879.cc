//盈利计划

//应该是0/1背包,原逻辑写成了完全背包,
//即应该依赖的i-1轮的项在i轮使用之前就被更新了,所以应该反着来
//截止到group[i],更简洁,且所依赖的一定小于当前的j,
//重要!!!
//因为dp[j-group[i]]一定是上一轮的,所以k的更新顺序不影响!!!

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int MOD = 1e9+7;

const int MAXN=100;
const int MAXM=100;

long long dp[MAXN+1][MAXM+1];

int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    memset(dp,0,sizeof(dp));
    int len=group.size();

    //最低利润为0时,不管已有人数是多少,没有工作时都有1个选择.
    for(int j=0;j<=n;j++) dp[j][0]=1;

    for(int i=0;i<len;i++){
        for(int j=n;j>=group[i];j--){
            for(int k=0;k<=minProfit;k++){
                dp[j][k]=(dp[j][k]+dp[j-group[i]][max(0,k-profit[i])])%MOD;
            }
        }
    }

    return dp[n][minProfit];
}

int main()
{
    vector<int> group={2,2};
    vector<int> profit={2,3};

    cout << profitableSchemes(5,3,group,profit);
}