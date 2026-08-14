//供暖器

//先排序，每次检查当前供暖器是否是当前房屋的最佳配置
//单调性在于最佳供暖器位置不回退

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

bool best(const vector<int>& houses,const vector<int>& heaters,int i,int j)
{
    //可能有重复的供暖器，得到相同的绝对值，导致永远返回true，注意要严格小于！！
    if(j+1==int(heaters.size()) || abs(houses[i]-heaters[j])<abs(houses[i]-heaters[j+1])) 
        return true;
    return false;
}

int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(),houses.end());
    sort(heaters.begin(),heaters.end());
    int ans=0;
    for(int i=0,j=0;i<int(houses.size());i++){
        while(!best(houses,heaters,i,j)) j++;
        ans=max(ans,abs(houses[i]-heaters[j]));
    }
    return ans;
}