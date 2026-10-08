//打家劫舍

#include<vector>
#include<algorithm>

using namespace std;

//dp[i]:到i位置最多偷到的金额
//=max(dp[i-2]+nums[i],dp[i-1])

int rob(vector<int>& nums) {
    int len=nums.size();
    if(len==1) return nums[0];
    int lastlast=nums[0],last=max(nums[0],nums[1]);
    for(int i=2,cur;i<len;i++){
        cur=max(lastlast+nums[i],last);
        lastlast=last;
        last=cur;
    }
    return last;
}