#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> ans;
    vector<int> q(n);
    int l=0,r=0;
    for(int i=0;i<n;i++){
        while(r-l>0 && nums[q[r-1]]<=nums[i]){
            r--;
        }
        q[r++]=i;
        if(q[l]<=i-k) l++;
        if(i-k+1>=0) ans.push_back(nums[q[l]]);
    }
    return ans;
}
