//可以翻转一次的情况下子数组最大累加和
//随意选择数组nums连续的一段进行翻转
//返回必须翻转一次之后,子数组的最大累加和

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int func(vector<int> &nums){
    int n=nums.size();
    if(n==0) return 0;

    //最大累加和的子数组
    //要么由不翻转的段(或者完全翻转的段组成,也包括在数组中间翻转的段)
    //要么由翻转和不翻转的段组成(两边都来一次)
    
    vector<int> prefix(n); // 以i结尾的最大子数组累加和
    //vector<int> maxprefix(n); // 0~i范围内的最大子数组累加和
    prefix[0]=nums[0];
    //maxprefix[0]=max(0,prefix[0]);
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]>=0?prefix[i-1]+nums[i]:nums[i];
        //maxprefix[i]=max(maxprefix[i-1],prefix[i]);
    }
    
    vector<int> suffix(n); // 以i结尾的最大子数组累加和
    vector<int> maxsuffix(n); // 0~i范围内的最大子数组累加和
    suffix[n-1]=nums[n-1];
    maxsuffix[n-1]=max(0,suffix[n-1]);
    for(int i=n-2;i>=0;--i){
        suffix[i]=suffix[i+1]>=0?suffix[i+1]+nums[i]:nums[i];
        maxsuffix[i]=max(maxsuffix[i+1],suffix[i]);
    }
    
    int res=*max_element(prefix.begin(),prefix.end());
    for(int i=0;i<n-1;i++){
        res=max(res,prefix[i]+maxsuffix[i+1]/*maxprefix[i],suffix[i+1]*/);
    }

    return res;
}