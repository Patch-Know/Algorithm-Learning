//前缀和最基础题
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int MAXN=1e4+5;

int sum[MAXN];


class NumArray {
public:
    NumArray(vector<int>& nums) {
        memset(sum,0,sizeof(sum));
        int pos=1;
        for(const int x:nums){
            sum[pos]=sum[pos-1]+x;
            pos++;
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right+1]-sum[left];
    }
};