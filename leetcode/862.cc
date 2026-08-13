// https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/

#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<limits.h>
using namespace std;

//和至少为k的最短子数组（单调队列）
int shortestSubarray(vector<int>& nums, int k){
    //if(nums.size()==0) return -1;
    int ans=INT_MAX; //没有满足条件的答案则返回-1
    int sum=0; //当前下标上的前缀和（也可以用数组代替）
    deque<pair<int,int>> q; //支持尾端弹出
    q.push_back({0,0}); //初始化
    for(int i=0;i<static_cast<int>(nums.size());i++){
        sum+=nums[i];
        while(!q.empty() && sum-q.front().second>=k){ //满足条件时结算
            ans=min(ans,i+1-q.front().first); //更新最短区间长度
            q.pop_front();
        }
        while(!q.empty() && q.back().second>=sum){ //多余=无用，尾端弹出
            q.pop_back();
        }
        q.push_back({i+1,sum});//+1偏移量，加入当前下标与累加和
    }
    return ans==INT_MAX ? -1 : ans;
}

int main()
{
    vector<int> v={2,-1,2};
    int k=3;
    cout << shortestSubarray(v,k) << endl;
    return 0;
}