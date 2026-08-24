// 拓扑排序模版（牛客）
// 链式前向星建图（静态方式）

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int MAXN=2e5+5;
const int MAXM=2e5+5;

int head[MAXN],nxt[MAXM],to[MAXM];

int indegree[MAXN];

int que[MAXN];

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
    int l=0,r=0;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) que[r++]=i;
    }
    while(l<r){
        int x=que[l++];
        for(int i=head[x];i!=-1;i=nxt[i]){
            if(--indegree[to[i]]==0) que[r++]=to[i];
        }
    }
    if(r!=n) cout << -1;
    else{
        for(int i=0;i<n-1;i++){
            cout << que[i] << ' ';
        }
        cout << que[n-1];
    }
    return 0;
}
