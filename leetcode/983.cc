#include<iostream>
#include<vector>
#include<cstring>
#include<limits.h>
#include<algorithm>
using namespace std;
//记忆化搜索，从顶到底
int dp[366];

int durations[3]={1,7,30};

int f1(const vector<int>& days,const vector<int>& costs,int i,int len)
{
    if(i==len) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans=INT_MAX;
    for(int k=0,j=i;k<3;k++){
        while(j<len && days[i]+durations[k]>days[j]) j++;
        ans=min(ans,f1(days,costs,j,len)+costs[k]);
    }
    dp[i]=ans;
    return ans;
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    memset(dp,-1,sizeof(dp));
    return f1(days,costs,0,static_cast<int>(days.size()));
}

// 严格位置依赖的动态规划，从底到顶

int mincostTickets3(vector<int>& days, vector<int>& costs) {
    int n=static_cast<int>(days.size());
    vector<int> dp(n+1,INT_MAX);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        for(int k=0,j=i;k<3;k++){
            while(j<n && days[i]+durations[k]>days[j]) j++;
                dp[i]=min(dp[i],dp[j]+costs[k]); // 同样的逻辑
        }
    }
    return dp[0];
}