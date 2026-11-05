//被7整除的子序列最大累加和

#include<iostream>
#include<vector>
#include<algorithm>
#include<random>

using namespace std;

int func(vector<int>& nums){
    const int NEG = -1;
    vector<int> dp(7, NEG);
    dp[0] = 0; // 空子序列

    for (int x : nums) {
        vector<int> ndp = dp;      // 不选 x
        int xm = x % 7;

        for (int r = 0; r < 7; r++) { //因为上个dp表每个都遍历到,所以从上个dp表的角度遍历也没问题
            if (dp[r] == NEG) continue;   // 不可达状态不能转移
            int nr = (r + xm) % 7;
            ndp[nr] = max(ndp[nr], dp[r] + x);
        }
        dp.swap(ndp);
    }

    return dp[0]; // 允许空子序列时至少为 0
}

int f(vector<int>& nums,int i,int s){
    if(i==static_cast<int>(nums.size())){
        return s%7==0?s:0;
    }
    return max(f(nums,i+1,s),f(nums,i+1,s+nums[i]));
}

int f_check(vector<int>& nums){return f(nums,0,0);}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> u(0,2000000);
    uniform_int_distribution<int> arr_len(1,24);
    for(int i=0;i<2000;i++){
        if(i%100==0) cout << i << endl;
        vector<int> temp;
        int n=arr_len(gen);
        temp.reserve(n);
        generate_n(back_inserter(temp),n,[&]{return u(gen);});
        for(int &x:temp) x=u(gen);
        if(f_check(temp)!=func(temp)){
            cout << "Wrong solution" << endl;
            return 0;
        }
    }
    cout << "Right" << endl;
}