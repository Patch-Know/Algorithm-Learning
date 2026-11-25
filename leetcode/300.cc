//最长递增子序列
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//normal
int lengthOfLIS0(vector<int> &nums) {
    int n=nums.size();
    vector<int> dp(n);
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}

//best
int lengthOfLIS(vector<int> &nums) {
    int n=nums.size();
    const int maxn=1e4+5;
    vector<int> dp(n);
    vector<int> ends(n,maxn); //ends[i]: 目前所有长度为i+1的递增子序列的最小结尾

    for(int i=0;i<n;i++){
        dp[i]=1;
        int l=0,r=i-1;
        while(l<=r){
            int m=(l+r)/2;
            if(ends[m]<nums[i]){
                dp[i]=(m+1)+1;
                l=m+1;
            }else{
                r=m-1;
            }
        }
        //update ends
        if(nums[i]<ends[dp[i]-1]){
            ends[dp[i]-1]=nums[i];            
        }
    }
    return *max_element(dp.begin(),dp.end());
}

//不下降
int lengthOfLIS2(vector<int> &nums) {
    int n=nums.size();
    const int maxn=1e4+5;
    vector<int> dp(n);
    vector<int> ends(n,maxn); //ends[i]: 目前所有长度为i+1的不下降子序列的最小结尾

    for(int i=0;i<n;i++){
        dp[i]=1;
        int l=0,r=i-1;
        while(l<=r){
            int m=(l+r)/2;
            if(ends[m]<=nums[i]){ //只改这一处
                dp[i]=(m+1)+1;
                l=m+1;
            }else{
                r=m-1;
            }
        }
        //update ends
        if(nums[i]<ends[dp[i]-1]){
            ends[dp[i]-1]=nums[i];            
        }
    }
    return *max_element(dp.begin(),dp.end());
}



int main()
{
    vector<int> nums{7,7,7,7,7,7,7,7};
    //cout << lengthOfLIS0(nums) << endl;
    cout << lengthOfLIS(nums) << endl;
    cout << lengthOfLIS2(nums) << endl;
}