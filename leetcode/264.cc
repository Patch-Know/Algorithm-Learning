//丑数II

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN=1700;

int dp[MAXN];

int nthUglyNumber(int n) {
    dp[1]=1;
    int p2=1,p3=1,p5=1;
    for(int i=1,next;i<n;i++){
        next=min(dp[p2]*2,min(dp[p3]*3,dp[p5]*5));
        if(dp[p2]*2==next) p2++;
        if(dp[p3]*3==next) p3++;
        if(dp[p5]*5==next) p5++;
        dp[i+1]=next;
    }
    return dp[n];
}

int main()
{
    cout << nthUglyNumber(10);
    return 0;
}