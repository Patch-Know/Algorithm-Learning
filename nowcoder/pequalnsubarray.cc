//给定一个无序数组arr，其中元素可正、可负、可0。求arr所有子数组中正数与负数个数相等的最长子数组的长度。

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int,int> map;
    map[0]=-1;
    int N;
    cin >> N;
    int ans=0;
    for(int i=0,sum=0,num;i<N; i++){
        cin >> num;
        sum+=num>0?1: (num==0?0:-1); //注意是三种情况！
        if(map.count(sum)!=0) ans=max(ans,i-map[sum]);
        else map[sum]=i;
    }
    cout << ans;
    return 0;
}