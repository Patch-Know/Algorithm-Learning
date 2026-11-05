//绝对差不超过限制的最长连续子数组

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestSubarray(vector<int> &nums,int limit){
    int n=nums.size();
    vector<int> q_max(n); //index
    vector<int> q_min(n); //index
    int l1=0,r1=0;
    int l2=0,r2=0;
    int l=0;
    int max_width=0;
    for(int i=0;i<n;i++){
        while(r1-l1>0 && nums[q_max[r1-1]]<=nums[i]){
            r1--;
        }
        q_max[r1++]=i;
        while(r2-l2>0 && nums[q_min[r2-1]]>=nums[i]){
            r2--;
        }
        q_min[r2++]=i;
        while(nums[q_max[l1]]-nums[q_min[l2]]>limit){
            l++;
            if(q_max[l1]<l) l1++;
            if(q_min[l2]<l) l2++;
        }
        max_width=max(max_width, i-l+1);

    }
    return max_width;
}

 int main()
 {
     vector<int> nums{4,2,2,2,4,4,2,2};
     int limit=0;
     cout << longestSubarray(nums,limit) << endl;
 }
