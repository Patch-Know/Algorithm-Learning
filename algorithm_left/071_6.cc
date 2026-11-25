//删掉1个数字后长度为k的子数组最大累加和

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

int func(vector<int> &nums,int k)
{
    int n=nums.size();

    vector<int> q(n); //维护区间最小值
    int l=0,r=0;
    int res=numeric_limits<int>::min();
    int cursum=0;
    for(int i=0;i<n;i++){
        int cur=nums[i];
        cursum+=cur;
        if(i>k) cursum-=nums[i-k-1];
        if(l<r &&q[l]<=i-k-1) l++;
        while(l<r && cur<=nums[q[r-1]]) r--;
        q[r++]=i;
        if(i>=k) res=max(res,cursum-nums[q[l]]);
    }
    return res;
}