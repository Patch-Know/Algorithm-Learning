//分割数组的最大值

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int f(const vector<int>& nums, int max_sum) //最大值不大于max_sum的前提下最少需要的组数
{
    int group=0;
    int sum=0;
    int len=static_cast<int>(nums.size());
    for(int i=0;i<len && group<=51;i++){
        if(sum+nums[i]>max_sum){
            group++;
            sum=nums[i];
        }else sum+=nums[i];
    }
    if(sum!=0) group++;
    return group;
}

int splitArray(vector<int>& nums, int k) {
    int l=0,r=0;
    for(auto x:nums){
        l=max(l,x);
        r+=x;
    }
    int ans;
    while(l<=r){
        int m=(l+r)/2;
        if(f(nums,m)<=k){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    return ans;
}