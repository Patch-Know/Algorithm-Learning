//打家劫舍II

#include<vector>
#include<algorithm>

using namespace std;

int rob(vector<int>& nums) {
    int len=nums.size();
    if(len==1) return nums[0];
    if(len==2) return max(nums[0],nums[1]);
    int lastlast=nums[0],last=max(nums[0],nums[1]);
    for(int i=2,cur;i<len-1;i++){
        cur=max(lastlast+nums[i],last);
        lastlast=last;
        last=cur;
    }
    int max1=last,max2;
    lastlast=nums[1],last=max(nums[1],nums[2]);
    for(int i=3,cur;i<len;i++){
        cur=max(lastlast+nums[i],last);
        lastlast=last;
        last=cur;
    }
    max2=last;

    return max(max1,max2);
}