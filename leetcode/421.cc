// 数组中两个数的最大异或值
// 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0<=i<=j<=n

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<unordered_set>

using namespace std;

//前缀树做法

const int MAXN=3e6+5;

int tree[MAXN][2];

int pass[MAXN];

int End[MAXN];

int numberOfLeadingZeros(const unsigned num)
{
    unsigned cnt=1u<<31;
    int ans=0;
    while(num & cnt){
        ans++;
        cnt>>=1;
    }
    return ans;
}


class TrieTree{
private:
    int cnt;
    int high;
public:
    TrieTree(const vector<int> nums):cnt(1)
    {
        int max=0;
        for(const int x:nums) max=std::max(max,x);
        high=31-numberOfLeadingZeros((unsigned)max);
    }

    void insert(int num)
    {
        int cur=1;
        pass[cur]++;
        for(int i=high,path;i>=0;i--){
            path=(num>>i)&1;
            if(tree[cur][path]==0){
                tree[cur][path]=++cnt;
            }
            cur=tree[cur][path];
            pass[cur]++;
        }
        End[cur]++;
    }

    int maxXor(int num)
    {
        int ans=0;

        int cur=1;
        for(int i=high,status,want;i>=0;i--){
            status=(num>>i)&1;
            want=status^1;
            if(tree[cur][want]==0){ //不能达成
                want^=1;
            }
            ans|=(status ^ want)<<i;
            // want变成真的往下走的路
            cur=tree[cur][want];
        }
        return ans;
    }

    

    void clear()
    {
        for(int i=1;i<=cnt;i++)
        {
            pass[i]=0;
            End[i]=0;
            memset(tree[i],0,sizeof(tree[i]));
        }
    }
};



int findMaximumXOR1(vector<int>& nums) {
    TrieTree box(nums);
    for(const int x:nums) box.insert(x);
    int ans=0;
    for(const int x:nums) ans=max(ans,box.maxXor(x));
    box.clear(); //一定要clear！！！不然leetcode不能通过，因为要多次调用！
    return ans;
}

//哈希表做法

int findMaximumXOR2(vector<int>& nums) {
    int max=0;
    for(const int x:nums) max=std::max(max,x);
    int ans=0;
    unordered_set<int> set;
    for(int i=31-numberOfLeadingZeros(max);i>=0;i--){
        set.clear();
        int better=ans|(1<<i);
        for(int num : nums){
            num=(num>>i)<<i; //消除低位
            set.insert(num);
            if(set.count(better^num)){
                ans=better;
                break;
            }
        }
    }
    return ans;
}