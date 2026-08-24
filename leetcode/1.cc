//两数之和

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int len=static_cast<int>(nums.size());
    unordered_map<int,int> map;
    for(int i=0;i<len;i++){
        if(map.count(target-nums[i])!=0) return {map[target-nums[i]],i};
        map[nums[i]]=i;
    }
    return {};
}

//lets VIM!!
