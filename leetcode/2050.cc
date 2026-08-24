//并行课程II

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<vector<int>> gragh(n+1);
    vector<int> indegree(n+1,0);
    indegree[0]=-1;
    for(const auto &edge:relations){ //其实可以映射为0到n-1
        gragh[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }
    vector<int> precost(n+1,0);
    vector<int> que(n);
    int l=0,r=0;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            que[r++]=i;
        } 
    }
    int ans=0;
    while(l<r){
        int cur=que[l++];
        if(gragh[cur].empty()) ans=max(ans,precost[cur]+time[cur-1]);
        for(int v:gragh[cur]){
            precost[v]=max(precost[v],precost[cur]+time[cur-1]);
            if(--indegree[v]==0) que[r++]=v;
        }
    }
    return ans;
}