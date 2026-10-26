//最大宽度坡
/*
给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]。这样的坡的宽度为 j - i。
找出 A 中的坡的最大宽度，如果不存在，返回 0 。
*/

#include <vector>
#include <algorithm>

using namespace std;

int maxWidthRamp(vector<int>& nums) {
    int max_width=0;
    int n=nums.size();
    vector<int> v(n);//index
    int r=1;

    for(int i=1;i<n;i++){
        if(nums[i]<nums[v[r-1]]){
            v[r++]=i;
        }
    }
    
    for(int i=n-1;i>=0;i--){
        while(r>0 && nums[i]>=nums[v[r-1]]) max_width=max(max_width,i-v[--r]);
    }

    return max_width;
}
