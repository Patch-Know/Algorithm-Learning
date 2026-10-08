//环形子数组的最大和

#include<algorithm>
#include<vector>

using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int len=nums.size();
    int minpre=nums[0],minsum=nums[0],maxpre=nums[0],maxsum=nums[0],all=nums[0];
    for(int i=1;i<len;i++){
        maxpre=max(nums[i],nums[i]+maxpre);
        maxsum=max(maxsum,maxpre);
        minpre=min(nums[i],nums[i]+minpre);
        minsum=min(minsum,minpre);
        all+=nums[i];
    }
    return all==minsum?maxsum:max(maxsum,all-minsum);
}