//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。
//解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
/*
示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

void f(const vector<int> & s,int i,vector<int> & path,vector<vector<int>> &set)
{
    int size=static_cast<int>(s.size());
    if(i==size){
        set.push_back(path);
        return;
    }
    int num=s[i];
    int r=i;
    while(r+1<size && num==s[r+1]) r++;
    int times=r-i+1;
    //不添加i位置元素
    f(s,r+1,path,set);
    //添加
    for(int i=0;i<times;i++){
        path.push_back(num);
        f(s,r+1,path,set);
    }
    for(int i=0;i<times;i++){
        path.pop_back();
    }  
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> path;
    sort(nums.begin(),nums.end());
    f(nums,0,path,ans);
    return ans;
}