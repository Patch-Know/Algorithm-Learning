//每日温度
//参考 newcoder->mono_stack_template

#include<iostream>
#include<vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n=temperatures.size();
    vector<int> ans_r(n,0),st(n);
    int r=0;
    for(int i=0;i<n;i++){ //遍历
        while(r>0 && temperatures[st[r-1]]<temperatures[i]){
            int pop=st[--r];
            ans_r[pop]=i-pop;
        }
        st[r++]=i;
    }
   
    return ans_r;
}