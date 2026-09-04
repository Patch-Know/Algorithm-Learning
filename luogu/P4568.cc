//P4568 [JLOI2011] 飞行路线

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;

const int MAXN=1e4+5;
const int MAXM=5e4+5;

int head[MAXN];
int to[MAXM*2];
int nxt[MAXM*2];
int weight[MAXM*2];

int cnt;

void addEdge(int u,int v,int w)
{
    to[++cnt]=v;
    weight[cnt]=w;
    nxt[cnt]=head[u];
    head[u]=cnt;
}

struct point
{
    int n,d,t;
    bool operator<(const point &other) const
    {
        return d>other.d;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(head,-1,sizeof(head));
    int n,m,k,s,t;
    cin >> n >> m >> k >> s >> t;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        addEdge(a,b,c);
        addEdge(b,a,c);
    }
    vector<int> dist((k+1)*n,INT_MAX);
    priority_queue<point> heap;

    dist[0*n+s]=0;
    heap.push({s,0,0});

    while(!heap.empty()){
        auto [city,distance,use_times]=heap.top();
        heap.pop();
        if(distance!=dist[use_times*n+city]) continue;
        if(city==t){
            cout << distance;
            return 0;
        }

        for(int e=head[city];e!=-1;e=nxt[e]){
            int v=to[e],w=weight[e];
            if(distance+w<dist[use_times*n+v]){
                dist[use_times*n+v]=distance+w;
                heap.push({v,distance+w,use_times});
            }
            if(use_times<k && distance<dist[(use_times+1)*n+v]){
                dist[(use_times+1)*n+v]=distance;
                heap.push({v,distance,use_times+1});
            }
        }
    }
    cout << -1;
}