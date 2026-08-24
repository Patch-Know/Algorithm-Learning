//参加会议的最多员工数

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//图已经由favorite数组建好了

int maximumInvitations(vector<int>& favorite) {
    int n=static_cast<int>(favorite.size());
    vector<int> indegree(n,0);
    for(int v:favorite) indegree[v]++;
    vector<int> que(n);
    int l=0,r=0;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) que[r++]=i;
    }
    // deep[i] : 不包括i在内，i之前的最长链的长度
    vector<int> deep(n,0);
    while(l<r){
        int cur=que[l++];
        int next=favorite[cur];
        deep[next]=max(deep[next],deep[cur]+1);
        if(--indegree[next]==0) que[r++]=next;
    }
    // 目前图中的点，不在环上的点，都删除了！ indegree[i] == 0
    // 可能性1 : 所有小环(中心个数 == 2)，算上中心点 + 延伸点，总个数
    int sumOfSmallRings=0;
    // 可能性2 : 所有大环(中心个数 > 2)，只算中心点，最大环的中心点个数
    int bigRings=0;
    for(int i=0;i<n;i++){
        if(indegree[i]>0){
            indegree[i]=0; //不会再来了
            int ringSize=1;
            for(int j=favorite[i];j!=i;j=favorite[j]){
                ringSize++;
                indegree[j]=0; //不会再来了
            }
            if(ringSize==2) sumOfSmallRings+=2+deep[i]+deep[favorite[i]];
            else bigRings=max(bigRings,ringSize);
        }
    }
    return max(bigRings,sumOfSmallRings);
}