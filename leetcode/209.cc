//长度最小的子数组

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
//左闭右开
int minSubArrayLen1(int target, vector<int>& nums) {
    int n=static_cast<int>(nums.size());
    int l=0,r=0,sum=0;
    int ans=INT_MAX;
    while(r<n){
        sum+=nums[r++];
        while(sum-nums[l]>=target){
            sum-=nums[l++];
        }
        if(sum>=target){
            ans=min(ans,r-l);
        }
    }
    return ans==INT_MAX?0:ans;
}