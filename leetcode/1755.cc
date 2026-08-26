//最接近目标值的子序列和

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void bfs(vector<int> &res,const vector<int> &price,int i,int n,int cost)
{
    if(i==n){
        res.push_back(cost);
        return;
    }
    bfs(res,price,i+1,n,cost);
    bfs(res,price,i+1,n,cost+price[i]);
}

int minAbsDifference(vector<int>& nums, int goal) {
    int N=nums.size();
    vector<int> l_arr,r_arr;
    bfs(l_arr,nums,0,N/2,0);
    bfs(r_arr,nums,N/2,N,0);
    sort(l_arr.begin(),l_arr.end());
    sort(r_arr.begin(),r_arr.end());
    int ans=INT_MAX;
    for(int i=0,j=r_arr.size()-1;i<static_cast<int>(l_arr.size());i++){
        while(j>0 && abs(goal-l_arr[i]-r_arr[j-1])<=abs(goal-l_arr[i]-r_arr[j])) j--;
        ans=min(ans,abs(goal-l_arr[i]-r_arr[j]));
    }
    return ans;
}