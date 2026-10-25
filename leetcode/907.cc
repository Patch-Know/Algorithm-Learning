//子数组的最小值之和

//罪孽的节点啊!(bushi)

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD=1e9+7;

int sumSubarrayMins(vector<int>& arr) {
    long long ans=0;
    int n=arr.size();
    vector<int> st(n); //index
    int r=0;
    for(int i=0;i<n;i++){
        while(r>0 && arr[st[r-1]]>arr[i]){
            int pop=st[--r];
            int multi_num=r>0?pop-st[r-1]:(pop+1);
            ans=(ans+1LL*multi_num*(i-pop)*arr[pop])%MOD;
        }
        st[r++]=i;
    }
    while(r>0){
        int pop=st[--r];
        int multi_num=r>0?pop-st[r-1]:(pop+1);
        ans=(ans+1LL*multi_num*(n-pop)*arr[pop])%MOD;
    }
    return ans;
}

int main()
{
    vector<int> arr{3,1,2,4};
    cout << sumSubarrayMins(arr);
}