//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void f(vector<int> & nums,int l,int r,vector<vector<int>> & ans)
{
    if(l>r){
        ans.push_back(nums);
        return;
    }

    for(int i=l;i<=r;i++){
        swap(nums[l],nums[i]);
        f(nums,l+1,r,ans);
        swap(nums[l],nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;  
    f(nums,0,static_cast<int>(nums.size())-1,ans);
    return ans;
}