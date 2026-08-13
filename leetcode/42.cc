//接雨水

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//辅助数组法
int trap1(vector<int>& height) {
    int len=static_cast<int>(height.size());
    vector<int> lmax(len),rmax(len);
    lmax[0]=height[0];
    for(int i=1;i<len;i++){
        lmax[i]=max(lmax[i-1],height[i]);
    }
    rmax[len-1]=height[len-1];
    for(int i=len-2;i>=0;i--){
        rmax[i]=max(rmax[i+1],height[i]);
    }
    int ans=0;
    for(int i=1;i<len-1;i++){
        ans+=max(0,min(lmax[i-1],rmax[i+1])-height[i]);
    }
    return ans;
}

//双指针法
int trap2(vector<int>& height) {
    int len=static_cast<int>(height.size());
    int lmax=height[0],rmax=height[len-1];
    int l=1,r=len-2,ans=0;
    while(l<=r){
        if(lmax<=rmax){
            if(lmax>height[l]) ans+=lmax-height[l++];
            else lmax=height[l++];
        }else{
            if(rmax>height[r]) ans+=rmax-height[r--];
            else rmax=height[r--];
        }
    }
    return ans;
}