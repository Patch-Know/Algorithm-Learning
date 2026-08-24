//一和零

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int zero,one;

void ctZerosandOnes(const string & s)
{
    zero=0;
    one=0;
    for(auto ch:s){
        if(ch=='0') zero++;
        else one++;
    }
}

#define HIDE
#ifndef HIDE

int dp[600][101][101]; //前i个字符串，在0不多于z个和1不多于o的情况下，最多能选几个
/**
 * case 1:zeros>z&&ones>o -> dp[i-1][z][o]
 * case 2:if not case1 -> max(dp[i-1][z][o],1+dp[i-1][z-zeros][o-ones])
 */


int findMaxForm(vector<string>& strs, int m, int n) {
    int len=static_cast<int>(strs.size());
    memset(dp,0,sizeof(dp));
    for(int i=0;i<len;i++){
        ctZerosandOnes(strs[i]);
        for(int z=0;z<=m;z++){
            for(int o=0;o<=n;o++){
                if(i==0) dp[i][z][o]=zero<=z&&one<=o?1:0;
                else dp[i][z][o]=zero<=z&&one<=o?max(dp[i-1][z][o],1+dp[i-1][z-zero][o-one]):dp[i-1][z][o];
            }
        }
    }
    return dp[len-1][m][n];
}
#endif

//空间压缩，画图理解，因为限制了行和列和宽度，所以不会依赖到已经更新过的值
int dp[101][101];

int findMaxForm(vector<string>& strs, int m, int n) {
    memset(dp,0,sizeof(dp));
    for(const auto & str : strs){
        ctZerosandOnes(str);
        for(int z=m;z>=zero;z--){
            for(int o=n;o>=one;o--){
                dp[z][o]=max(dp[z][o],1+dp[z-zero][o-one]);
            }
        }
    }
    return dp[m][n];
}