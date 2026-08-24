//FoodLines

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN=5e3+5;

const int MAXM=5e5+5;

const int mod=80112002;

int head[MAXN];

int nxt[MAXM];

int to[MAXM];


int cnt;

void addEdge(int u,int v)
{
    to[++cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}

ll kinds[MAXN];

int indegree[MAXN];

int que[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(head,-1,sizeof(head));
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        addEdge(u,v);
        indegree[v]++;//其实这句应该和加边逻辑分离的
    }
    int l=0,r=0;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            que[r++]=i;
            kinds[i]=1;
        }
    }
    ll ans=0;
    while(l<r){
        int cur=que[l++];
        if(head[cur]==-1) ans=(ans+kinds[cur])%mod;
        else{
            for(int ei=head[cur];ei!=-1;ei=nxt[ei]){
                kinds[to[ei]]=(kinds[to[ei]]+kinds[cur])%mod;
                if(--indegree[to[ei]]==0) que[r++]=to[ei];
            }
        }
    }
    cout << ans;
    return 0;
}