//戳印序列（拓扑排序）

//核心：由拓扑排序，取出入度为0的位置，遍历该位置上len个点（visited数组标记哪些已经访问过），
//通过之前建好的由点指向位置的邻接表，分别减去依赖该点修补的所有位置的入度（初始化为len，先都遍历一遍，获得拓扑排序前的真正入度），
//相当于完成了由位置到点再到位置的映射，完成拓扑排序，最后逆序输出

//入度表存储的是位置，和图（点到位置）是对应的，而排序的队列储存的是入度为0的位置
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> movesToStamp(string stamp, string target) {
    int len=static_cast<int>(stamp.length());
    int n=static_cast<int>(target.length());
    vector<int> indegree(n-len+1,len); //以前n-len+1的位置开头的入度,默认都错
    vector<vector<int>> gragh(n);
    vector<int> que(n-len+1);
    int l=0,r=0;
    for(int i=0;i<=n-len;i++){ //按开头位置依次遍历，不会重复
        for(int j=0;j<len;j++){
            if(target[i+j]==stamp[j]){
                if(--indegree[i]==0) que[r++]=i;
            }else gragh[i+j].push_back(i); //i+j位置要先补错，实际是后覆盖,
            //后续补错完成遍历时就能知道该减哪些位置的入度
        }
    }
    //同一个位置，取消错误不要重复统计！！
    vector<bool> visited(n,false);
    vector<int> path(n-len+1); //收集入度为0出来的位置
    int size=0;
    while(l<r){
        int cur=que[l++];
        path[size++]=cur;
        for(int i=0;i<len;i++){
            if(!visited[cur+i]){
                visited[cur+i]=true;
                for(int v:gragh[cur+i]){
                    if(--indegree[v]==0) que[r++]=v; 
                }
            }
        }
        
    }
    if(size!=n-len+1) return vector<int>{};
    reverse(path.begin(),path.end());
    return path;
}