//盛最多水的容器

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int len=static_cast<int>(height.size());
    int l=0,r=len-1,ans=0;
    while(l<r){
        ans=max(ans,(r-l)*min(height[l],height[r]));
        if(height[l]<height[r]) l++;
        else r--;
    }
    return ans;
}