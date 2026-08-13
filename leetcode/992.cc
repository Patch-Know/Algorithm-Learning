#include<iostream>
#include<vector>

using namespace std;

int subarraysWithKDistinct0(vector<int>& nums, int k) {
    int len=static_cast<int>(nums.size());
    vector<int> cnts(len,0);
    int ans=0;
    int kind=0;
    for(int l=0,r=0;r<len;r++){
        if(cnts[nums[r]-1]++==0) kind++;
        if(kind==k){
            ans++;
            int other=l;
            while(other>0 && cnts[nums[--other]-1]>0) ans++; //不滑，悲
        }
        if(kind>=k){
            while(cnts[nums[l]-1]>1 || kind>k){
                if(--cnts[nums[l++]-1]==0) kind--;
                if(kind==k) ans++;
            }
        }
    }
    return ans;
}

//技巧：严格等于变成小于等于（不超过）之差！！



int numsOfMostKinds(vector<int>& nums, int k) {
    int len=static_cast<int>(nums.size());
    vector<int> cnts(len,0);
    int ans=0;
    for(int l=0,r=0,kind=0;r<len;r++){
        if(cnts[nums[r]-1]++==0) kind++;
        if(kind>k){
            while(--cnts[nums[l++]-1]>0); //l对应的频数先减，看看是否达成条件（是否继续），最后递增l
            kind--;
        }
        ans+=r-l+1;
    }
    return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return numsOfMostKinds(nums,k)-numsOfMostKinds(nums,k-1);
}