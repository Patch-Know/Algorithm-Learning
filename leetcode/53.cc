//最大子数组和

#include<vector>
#include<algorithm>

using namespace std;

int maxSubArray1(vector<int>& nums) {
    int len=nums.size();
    vector<int> dp(len);
    dp[0]=nums[0];
    int ans=nums[0];
    for(int i=1;i<len;i++){
        dp[i]=max(nums[i],dp[i-1]+nums[i]);
        ans=max(ans,dp[i]);
    }
    return ans;
}

int maxSubArray2(vector<int>& nums) {
    int len=nums.size();
    int pre=nums[0];
    int ans=nums[0];
    for(int i=1;i<len;i++){
        pre=max(nums[i],pre+nums[i]);
        ans=max(ans,pre);
    }
    return ans;
}