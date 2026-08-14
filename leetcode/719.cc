//找出第k小的数对距离

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int f(const vector<int> & nums,int limit) //距离不大于limit的数对数量
{
    int len=static_cast<int>(nums.size());
    int ans=0;
    for(int l=0,r=0;l<len-1;l++){
        while(r+1<len && nums[r+1]-nums[l]<=limit) r++;
        ans+=r-l;
    }
    return ans;
}

int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int l=0,r=nums[nums.size()-1]-nums[0];
    int ans;
    while(l<=r){
        int m=(l+r)/2;
        if(f(nums,m)>=k){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    return ans;
}