//最大频率栈（删除时频率减一）
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class FreqStack {
private:
    vector<stack<int>> s_arr;
    unordered_map<int,int> fm;
public:
    FreqStack() {
    }
    
    void push(int val) {
        fm[val]++;
        if(fm[val]>static_cast<int>(s_arr.size())){
            s_arr.push_back(stack<int>({val}));
            return;
        }
        s_arr[fm[val]-1].push(val);
    }
    
    int pop() {
        int top_idx=static_cast<int>(s_arr.size())-1;
        int ans=s_arr[top_idx].top();
        fm[ans]--;
        if(fm[ans]==0) fm.erase(ans);
        s_arr[top_idx].pop();
        if(s_arr[top_idx].empty()) s_arr.pop_back();
        return ans;
    }
};