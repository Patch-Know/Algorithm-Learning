//喧闹和富有

#include<iostream>
#include<vector>

using namespace std;

vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    int n=static_cast<int>(quiet.size());
    vector<vector<int>> gragh(n);
    vector<int> indegree(n,0);
    for(const auto &edge:richer){
        gragh[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

    vector<int> ans(n);
    for(int i=0;i<n;i++){
        ans[i]=i;
    }

    vector<int> que(n);
    int l=0,r=0;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) que[r++]=i;
    }
    while(l<r){
        int cur=que[l++];
        for(int v:gragh[cur]){
            if(quiet[ans[cur]]<quiet[ans[v]]) ans[v]=ans[cur];
            if(--indegree[v]==0) que[r++]=v;
        }
    }

    return ans;
}