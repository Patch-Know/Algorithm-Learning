//将数组和减半的最少操作次数

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int halveArray(vector<int>& nums) {
    priority_queue<double> heap;
    double sum=0;
    for(double num:nums){
        heap.push(num);
        sum+=num;
    }
    sum/=2;
    int ans=0;
    for(double minus=0,cur;minus<sum-1e-6;ans++,minus+=cur){
        cur=heap.top()/2;
        heap.pop();
        heap.push(cur);
    }
    return ans;
}