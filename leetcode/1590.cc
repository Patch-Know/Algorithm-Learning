//移除最短子数组，使数组和能被p整除

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//数组版
int minSubarray1(vector<int>& nums, int p) {
    vector<int> sum(nums.size());
    int len=static_cast<int>(nums.size());
    sum[0]=nums[0]%p;
    for(int i=1;i<len;i++) sum[i]=(sum[i-1]+nums[i]%p)%p;
    if(sum[len-1]==0) return 0;
    int del=sum[len-1];
    unordered_map<int,int> map;
    map[0]=-1;
    int ans=-1;
    for(int i=0;i<len;i++){
        if(map.count((sum[i]-del+p)%p)!=0){
            if(ans==-1 || ans>i-map[(sum[i]-del+p)%p]) 
                ans=i-map[(sum[i]-del+p)%p]; //从被减位置的后一个位置
                //到i位置是应该移除的子数组
        }
        map[sum[i]]=i;
    }
    return ans==len?-1:ans;
}

//不用数组版

int minSubarray2(vector<int>& nums, int p) {
    int len=static_cast<int>(nums.size());
    int mod=0;
    for(int i=0;i<len;i++) mod=(mod+nums[i]%p)%p;
    if(mod==0) return 0;
    unordered_map<int,int> map;
    map[0]=-1;
    int ans=-1;
    for(int i=0,sum=0;i<len;i++){
        sum=(sum+nums[i])%p;
        if(map.count((sum-mod+p)%p)!=0){
            if(ans==-1 || ans>i-map[(sum-mod+p)%p]) 
                ans=i-map[(sum-mod+p)%p]; //从被减位置的后一个位置
                //到i位置是应该移除的子数组
        }
        map[sum]=i;
    }
    return ans==len?-1:ans;
}