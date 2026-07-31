//使数组按非递减顺序排列
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int totalSteps(vector<int>& nums) {
    int n=static_cast<int>(nums.size());
    int ans=0;
    int cur_turns;
    stack<pair<int,int>> st{};
    for(int i=n-1;i>=0;--i){
        cur_turns=0;
        while(!st.empty() && st.top().first < nums[i]){
            cur_turns=max(cur_turns+1,st.top().second);
            st.pop();
        }
        st.push({nums[i],cur_turns});
        ans=max(ans,cur_turns);
    }
    return ans;
}

int main()
{
    vector<int> nums{4,5,7,7,13};
    cout << totalSteps(nums) << endl;
}