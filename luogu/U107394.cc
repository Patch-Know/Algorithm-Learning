// 拓扑排序模版（洛谷）
// 链式前向星建图（静态方式）
//字典序输出（小根堆）

#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN=1e5+5;
const int MAXM=1e5+5;

int head[MAXN],nxt[MAXM],to[MAXM];

int indegree[MAXN];

int cnt=0;

void addEdge(int u,int v)
{
    to[++cnt]=v; //从1开始编号
    nxt[cnt]=head[u];
    head[u]=cnt;
    indegree[v]++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(head,-1,sizeof(head));
    int n,m;
    cin >> n >> m;
    int u,v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        addEdge(u,v);
    }
    priority_queue<int,vector<int>,greater<int>> que; //小根堆
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) que.push(i);
    }
    while(!que.empty()){
        int x=que.top();
        que.pop();
        cout << x << ' ';
        for(int i=head[x];i!=-1;i=nxt[i]){
            if(--indegree[to[i]]==0) que.push(to[i]);
        }
    }
    
    return 0;
}
