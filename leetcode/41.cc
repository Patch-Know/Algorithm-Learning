//缺失的第一个正数

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// [r....]垃圾区

//思路：把合理的数字一个个放到正确的位置上，不合理的数丢到垃圾区，并降低合理预期

int firstMissingPositive(vector<int>& nums) {
    int len=static_cast<int>(nums.size());
    int l=0,r=len;
    while(l<r){
        if(nums[l]==l+1) l++;
        else if(nums[l]<=l || nums[l]>r || nums[nums[l]-1]==nums[l]) //第三种情况是这个位置的数应该待的位置上已经有这个数了，垃圾
            swap(nums[l],nums[--r]); //预期降低
        else swap(nums[l],nums[nums[l]-1]); //待到应该待的位置上
    }
    return l+1;
}

int main()
{
    vector<int> nums{7,8,9,11,12};
    int ans=firstMissingPositive(nums);
    cout << ans;
    return 0;
}