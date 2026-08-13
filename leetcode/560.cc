//和为k的子数组的数量

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> map; //sum->cnt
    map[0]=1;
    int len=static_cast<int>(nums.size());
    int ans=0;
    for(int i=0,sum=0;i<len;i++){
        sum+=nums[i];
        if(map.count(sum-k)!=0) ans+=map[sum-k];
        map[sum]++;
    }
    return ans;
}
int main()
{
    
    return 0;
}