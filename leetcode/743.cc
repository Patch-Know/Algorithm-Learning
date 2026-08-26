//networkDelayTime
//Dijkstra

//normal

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN=105;
const int MAXM=6e3+5;

int head[MAXN];
int nxt[MAXM];
int to[MAXM];
int weight[MAXM];

int cnt;

void addEdge(int u,int v,int w)
{
    to[++cnt]=v;
    weight[cnt]=w;
    nxt[cnt]=head[u];
    head[u]=cnt;
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    cnt=0; //注意重复调用!!
    memset(head,-1,sizeof(head));
    vector<bool> visited(n+1,false);
    vector<int> dist(n+1,INT_MAX);
    typedef pair<int,int> pii; //dist & number
    priority_queue<pii,vector<pii>,greater<pii>> heap;

    for(const auto &v:times){
        addEdge(v[0],v[1],v[2]);
    }

    dist[k]=0;
    heap.push({dist[k],k}); //添加距离信息入堆
    while(!heap.empty()){
        auto [d,u]=heap.top();
        heap.pop();
        if(!visited[u]){ //可能多次添加同一个节点,排除旧值
            visited[u]=true;
            for(int e=head[u];e!=-1;e=nxt[e]){
                int v=to[e],w=weight[e];
                if(!visited[v] && d+w<dist[v]){
                    dist[v]=d+w;
                    heap.push({dist[v],v});
                }
            }
        }
    }
    
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]) return -1;
        ans=max(ans,dist[i]);
    }
    return ans;
}