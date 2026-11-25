//魔法卷轴
//给定整数数组nums
//每个魔法卷轴可以使数组中连续的一段变成0
//最多可使用2个魔法卷轴
//请返回数组整体尽可能大的累加和
//对数器验证

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int func(vector<int> nums)
{
    int n=nums.size();
    if(n==0) return 0;
    
    //不用卷轴
    int p1=0;
    for(int x:nums) p1+=x;

    //prefix[i]:0~i必须用一次,0~i累加和最大值
    vector<int> prefix(n);
    prefix[0]=0;
    int presum=nums[0];
    int maxpresum=max(0,nums[0]);
    for(int i=1;i<n;i++){ //关键算法:前面卷轴累加和加自身or前面最大累加和(自身到前面最大累加和后一个位置置0)
        prefix[i]=max(prefix[i-1]+nums[i],maxpresum);
        presum+=nums[i];
        maxpresum=max(maxpresum,presum);
    }

    //必须用1次卷轴
    int p2=prefix[n-1];

    //suffix[i]:i~n-1必须用一次,i~n-1累加和最大值
    vector<int> suffix(n);
    suffix[n-1]=0;
    //复用
    presum=nums[n-1];
    maxpresum=max(0,nums[n-1]);
    for(int i=n-2;i>=0;--i){
        suffix[i]=max(nums[i]+suffix[i+1],maxpresum);
        presum+=nums[i];
        maxpresum=max(maxpresum,presum);
    }
    
    //必须用2次卷轴
    int p3=INT32_MIN;
    for(int i=1;i<n;i++){
        p3=max(p3,prefix[i-1]+suffix[i]);
    }
    
    return max(p1,max(p2,p3));
}
