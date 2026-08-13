//表现良好的最长时间段

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int longestWPI(vector<int>& hours) {
    unordered_map<int,int> map;
    map[0]=-1;//0这个前缀和最早出现的位置是-1
    int ans=0;
    int len=static_cast<int>(hours.size());
    for(int i=0,sum=0;i<len;i++){
        sum+= hours[i]>8? 1 : -1;
        if(sum>0) ans=i+1;//目前为止表现良好
        else if(map.count(sum-1)!=0){
            ans=max(ans,i-map[sum-1]);
        }
        if(map.count(sum)==0) map[sum]=i;
    }    
    return ans;
}