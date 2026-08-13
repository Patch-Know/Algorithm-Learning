//寻找重复数
//快慢指针

#include<iostream>
#include<vector>

using namespace std;

int findDuplicate(vector<int>& nums) {
    int fast=0,slow=0;
    do{
        fast=nums[nums[fast]];
        slow=nums[slow];
    }while(fast!=slow);
    fast=0;
    while(fast!=slow){
        fast=nums[fast];
        slow=nums[slow];
    }
    return fast;
}

int main()
{
    vector<int> nums{3,1,3,4,2};
    cout << findDuplicate(nums);
    return 0;
}