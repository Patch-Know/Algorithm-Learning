//#define Kruskal

#ifdef Kruskal
// Kruskal算法模版（洛谷）
// 时间复杂度O(m * log m) + O(n + m)
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=5e3+1;

const int MAXM=2e5+1;

int father[MAXN];

/*
edges 的每个元素是 int[3] 类型，
C++ 中数组不能直接赋值，
也不满足 MoveAssignable/MoveConstructible 要求，
故不能作为 std::sort 的元素类型。
*/

struct Edge {
    int u, v, w;
};
Edge edges[MAXM];  // 替换二维数组

int n,m;

void build()
{
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
}

int find(int i)
{
    if(i!=father[i]){
        father[i]=find(father[i]);
    }
    return father[i];
}

bool Union(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        father[fx]=fy;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    build();
    for(int i=0;i<m;i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges,edges+m,[](const auto &a,const auto &b){return a.w<b.w;});
    int ans = 0;
    int edgeCnt = 0;
    for(int i=0;i<m;i++){
        if(Union(edges[i].u,edges[i].v)){
            edgeCnt++;
            ans+=edges[i].w;
        }
    }
    if(edgeCnt==n-1) cout << ans;
    else cout << "orz";
    return 0;
}
#else
//Prim+optimize
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN=5e3+1;

const int MAXM=2e5+1;

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

struct point{
    int u; //number
    int w; //weight
    bool operator<(const point & other) const
    {
        return w<other.w;
    }
};

template<typename T> //T:point
class Heap{
private:
    T arr[MAXN];
    int pos[MAXN]; //index
    int size;

    void swap(int i, int j) {
        T tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        pos[arr[i].u] = i;
        pos[arr[j].u] = j;
    }

    void heapInsert(int i)
    {
        while(arr[i]<arr[(i-1)/2]){
            Heap::swap(i,(i-1)/2);
            i=(i-1)/2; //记得更新
        }
    }

    void heapify(int i)
    {
        int child=i*2+1;
        while(child<size){
            if(child+1<size && arr[child+1]<arr[child]) child++;
            if(arr[child]<arr[i]){
                Heap::swap(i,child);
                i=child;
                child=i*2+1;
            }else break;
        }        
    }
public:
    Heap():size(0)
    {
        memset(arr,0,sizeof(arr));
        memset(pos,-1,sizeof(pos));
    }
    const auto & top(){return arr[0];}
    bool empty(){return size==0;}
    void push(T t)
    {
        arr[size++]=t;
        pos[arr[size-1].u]=size-1;
        heapInsert(size-1);
    }
    void pop(){
        swap(0, --size);   // 交换后，v 在 arr[size]
        pos[arr[size].u]=-1;
        if(size > 0) heapify(0);
    }
    void adjust(T t)
    {
        if(pos[t.u]==-1) push(t);
        else if(t<arr[pos[t.u]]){
            arr[pos[t.u]]=t;
            heapInsert(pos[t.u]); //up up!!
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(head,-1,sizeof(head));
    cnt=0;
    Heap<point> heap;
    int N,M;
    cin >> N >> M;
    for(int i=0,u,v,w;i<M;i++){
        cin >> u >> v >> w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    vector<bool> visited(N+1,false);
    visited[1]=true;
    long long ans=0;int total=1;
    for(int e=head[1];e!=-1;e=nxt[e]){
        heap.adjust({to[e],weight[e]});
    }
    while(!heap.empty()){
        auto [u,w]=heap.top();
        heap.pop();
        if(visited[u]) continue;//原来这一行这么重要的吗?
        visited[u]=true;
        ans+=w;
        total++;
        for(int e=head[u];e!=-1;e=nxt[e]){
            if(!visited[to[e]]){
                heap.adjust({to[e],weight[e]});
            }
        }
    }
    if(total==N) cout << ans;
    else cout << "orz";
}

#endif