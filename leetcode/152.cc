//乘积最大子数组

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int>& nums){
    int n=nums.size();
    vector<int> dp_max(n);
    vector<int> dp_min(n);
    int ans=*max_element(nums.begin(),nums.end());
    dp_max[0]=nums[0];
    dp_min[0]=nums[0];

    for(int i=1;i<n;i++){
        dp_max[i]=max(nums[i],max(nums[i]*dp_max[i-1],nums[i]*dp_min[i-1]));
        dp_min[i]=min(nums[i],min(nums[i]*dp_max[i-1],nums[i]*dp_min[i-1]));
        ans=max(ans,dp_max[i]);
    }

    return ans;
}
