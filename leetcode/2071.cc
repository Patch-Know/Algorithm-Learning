//你可以安排的最多任务数目

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//当前可以处理的元素加入队列
//正常模式从头弹出
//嗑药模式从尾弹出
//全部处理完返回true
//想嗑药没药了或者嗑药也没用返回false

bool f(vector<int>& tasks, vector<int>& workers, int pills, int strength,int nums)
{
    vector<int> q(nums);
    int l=0,r=0;
    int m=workers.size();
    int pt=0;
    for(int i=m-nums;i<m;i++){
        while(pt<nums && tasks[pt]<=workers[i]){
            q[r++]=tasks[pt++];
        }
        if(l<r&&q[l]<=workers[i]){
            l++;
            continue;
        }
        if(pills==0) return false;
        int plus=workers[i]+strength;
        pills--;
        while(pt<nums && tasks[pt]<=plus){
            q[r++]=tasks[pt++];
        }
        if(l<r&&q[r-1]<=plus){
            r--;
        }else{
            return false;
        }
    }
    return true;

}


int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    sort(tasks.begin(),tasks.end());
    sort(workers.begin(),workers.end());
    int max_tasks=workers.size();
    int n=tasks.size();
    int l=0,r=min(n,max_tasks);
    int ans=0;
    while(l<=r){
        int m=(l+r)/2;
        if(f(tasks,workers,pills,strength,m)){
            ans=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return ans;
}

int main()
{
    vector<int> tasks{5,4};
    vector<int> workers{0,0,0};
    int pills=1,strength=5;
    cout << maxTaskAssign(tasks,workers,pills,strength);
}
