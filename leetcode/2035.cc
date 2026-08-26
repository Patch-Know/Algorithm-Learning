//将数组分成两个数组并最小化数组和的差

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//s:sum
void collection(vector<vector<int>> &res,const vector<int> &nums,int i,int end,int s,int c)
{
    if(i==end) res[c].push_back(s);
    else{
        int j=i+1;
        while(j<end && nums[j]==nums[i]) j++;
        for(int k=0;k<=j-i;k++){
            collection(res,nums,j,end,s+k*nums[i],c+k);
        }
    }
}

int minimumDifference(vector<int>& nums) {
    int n=nums.size()/2;
    int sum=0;
    for(int num:nums) sum+=num;
    sort(nums.begin(),nums.end());
    vector<vector<int>> larr(n+1),rarr(n+1);
    collection(larr,nums,0,n,0,0);
    collection(rarr,nums,n,2*n,0,0);
    for(auto &v:larr) sort(v.begin(),v.end());
    for(auto &v:rarr) sort(v.begin(),v.end());
    int ans=INT_MAX;
    for(int c=0;c<=n;c++){
        const auto &la=larr[c];
        const auto &ra=rarr[n-c];
        for(int i=0,j=ra.size()-1;i<static_cast<int>(la.size());i++){
            while(j>0 && abs(sum-2*la[i]-2*ra[j-1])<=abs(sum-2*la[i]-2*ra[j])) j--;
            ans=min(ans,abs(sum-2*la[i]-2*ra[j]));
        }
    }
    return ans;
}