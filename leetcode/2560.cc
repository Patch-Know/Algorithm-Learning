//打家劫舍IV

#include<vector>
#include<algorithm>

using namespace std;


//返回窃取能力为money时能够窃取的最多房屋数
int f(vector<int>& nums,int money)
{
    int len=nums.size();
    if(len==1) return nums[0]<=money?1:0;
    if(len==2) return (nums[0]<=money || nums[1]<=money)?1:0;
    int lastlast=nums[0]<=money?1:0;
    int last=(nums[0]<=money || nums[1]<=money)?1:0;
    for(int i=2,cur;i<len;i++){
        cur=nums[i]<=money?lastlast+1:last;
        lastlast=last;
        last=cur;
    }
    return last;
}

int f_plus(vector<int>& nums,int money,int k)
{
    int count=0;
    bool flag=true;
    for(int num:nums){
        if(num<=money && flag){
            count++;
            flag=false;
            if(count>=k) break;
        }else flag=true;
    }
    return count;
}


//小偷总能窃取至少 k 间房屋。
//返回小偷的 最小 窃取能力。
int minCapability(vector<int>& nums, int k) {
    int r=*max_element(nums.begin(),nums.end());
    int l=*min_element(nums.begin(),nums.end());
    int ans=INT_MAX;
    while(l<=r){
        int m=(l+r)/2;
        if(f_plus(nums,m,k)>=k){
            ans=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
    return ans;
}

//贪心优化:偷过了立刻i++