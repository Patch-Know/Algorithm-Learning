// 有重复项数组的去重全排列
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

void f(vector<int> & nums,int l,int r,vector<vector<int>> & ans)
{
    if(l>r){
        ans.push_back(nums);
        return;
    }
    //遇到重复项就忽略，不只是与l位置，是每个位置之间不重复
    unordered_set<int> set;
    for(int i=l;i<=r;i++){
        if(!set.count(nums[i])){
            set.insert(nums[i]);
            swap(nums[l],nums[i]);
            f(nums,l+1,r,ans);
            swap(nums[l],nums[i]);
        }
        
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;  
    f(nums,0,static_cast<int>(nums.size())-1,ans);
    return ans;
}