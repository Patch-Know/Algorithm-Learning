//按奇偶排序数组II

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> sortArrayByParityII(vector<int>& nums) {
    int len=static_cast<int>(nums.size());
    vector<int> ans(nums);
    for(int odd=1,even=0;odd < len && even < len;){
        if((ans[len-1]&1)==1){
            swap(ans[odd],ans[len-1]);
            odd+=2;
        }else{
            swap(ans[even],ans[len-1]);
            even+=2;
        }
    }
    return ans;
}
