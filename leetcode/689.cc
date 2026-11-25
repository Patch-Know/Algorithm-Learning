//三个无重叠子数组的最大和

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n=nums.size();

    vector<int> ksum(n-k+1);
    for(int i=0;i<k;i++){
        ksum[0]+=nums[i];
    }
    int maxsum=ksum[0];
    vector<int> prefix(n);
    prefix[k-1]=0;
    for(int i=1;i<n-k+1;i++){
        ksum[i]=ksum[i-1]+nums[i+k-1]-nums[i-1];
        prefix[i+k-1]=ksum[i]>ksum[prefix[i+k-2]]?i:prefix[i+k-2];
    }
    vector<int> suffix(n);
    suffix[n-k]=n-k;
    for(int i=n-k-1;i>=0;--i){
        suffix[i]=ksum[i]>=ksum[suffix[i+1]]?i:suffix[i+1];
    }
    //wc!中间k滑动,一次性三分!为什么不早点告诉我!!!NB!!!
    maxsum=INT32_MIN;
    vector<int> res(3,-1);
    for(int i=k;i<n-k*2+1;i++){
        int temp=ksum[prefix[i-1]]+ksum[i]+ksum[suffix[i+k]];
        if(temp>maxsum){
            maxsum=temp;
            res={prefix[i-1],i,suffix[i+k]};
        }
    }
    return res;
}

int main()
{
    vector<int> nums{1,2,1,2,6,7,5,1};
    int k=2;
    for(auto i:maxSumOfThreeSubarrays(nums,k)){
        cout << i << ' ';
    }
}