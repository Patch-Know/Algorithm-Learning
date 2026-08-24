//课程表II
//拓扑排序
//邻接表建图（动态方式）

#include<iostream>
#include<vector>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> gragh(numCourses); //邻接表
    vector<int> indegree(numCourses,0);    //入度表
    for(const auto & edge:prerequisites){  //建图和填入度表
        gragh[edge[1]].push_back(edge[0]);
        indegree[edge[0]]++;
    }
    vector<int> que(numCourses); //拓扑排序队列兼答案
    int l=0,r=0;
    for(int i=0;i<numCourses;i++){ //获取最初入度为0的点
        if(indegree[i]==0) que[r++]=i;
    }
    int cnt=0;
    while(l<r){ //拓扑排序主流程
        int cur=que[l++];
        cnt++;
        for(int next:gragh[cur]){
            if(--indegree[next]==0) que[r++]=next;
        }
    }
    return cnt==numCourses?que:vector<int>{}; //无环则返回拓扑排序队列，否则返回空数组
}