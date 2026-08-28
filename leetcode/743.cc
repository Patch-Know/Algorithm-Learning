//networkDelayTime
//Dijkstra

//normal

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

//#define NORMAL

#ifdef NORMAL
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

#else
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

struct point{
    int u; //number
    int w; //weight
    bool operator<(const point & other) const
    {
        return w<other.w;
    }
};

//反向索引堆NB!!
//就是在普通堆的基础上排除了重复节点,做到改变权重并移动节点
template<typename T> //T:point
class Heap{
private:
    T arr[MAXN];
    int pos[MAXN]; //index
    int size;
    //交换节点值和索引
    void swap(int i, int j) { //封装了交换节点索引的操作
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

    void push(T t) //加新节点
    {
        arr[size++]=t;
        pos[arr[size-1].u]=size-1; //入堆更新索引
        heapInsert(size-1);
    }

    void pop(){
        swap(0, --size);   // 交换后，v 在 arr[size]
        pos[arr[size].u]=-1; //出堆更新索引
        if(size > 0) heapify(0);
    }

    void adjust(T t)
    {
        if(pos[t.u]==-1) push(t);
        else if(t<arr[pos[t.u]]){
            arr[pos[t.u]]=t; //调整更新值,移交上滤操作更新索引
            heapInsert(pos[t.u]); //up up!!
        }
    }
};

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    cnt=0; //注意重复调用!!
    memset(head,-1,sizeof(head));
    vector<bool> visited(n+1,false);
    vector<int> dist(n+1,INT_MAX);
    for(const auto &v:times){
        addEdge(v[0],v[1],v[2]);
    }
    Heap<point> heap;


    dist[k]=0;
    heap.adjust({k,dist[k]}); //添加距离信息入堆
    while(!heap.empty()){
        auto [u,d]=heap.top();
        heap.pop();
        if(!visited[u]){ //可能多次添加同一个节点,排除旧值
            visited[u]=true;
            for(int e=head[u];e!=-1;e=nxt[e]){
                int v=to[e],w=weight[e];
                if(!visited[v] && d+w<dist[v]){
                    dist[v]=d+w;
                    heap.adjust({v,dist[v]});
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
#endif