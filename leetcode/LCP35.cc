//电动车游城市

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int MAXN=105;
const int MAXM=405; //双向边加倍

int head[MAXN];
int to[MAXM];
int nxt[MAXM];
int weight[MAXM];

int Cnt;

void addEdge(int u,int v,int w)
{
    to[++Cnt]=v;
    weight[Cnt]=w;
    nxt[Cnt]=head[u];
    head[u]=Cnt;
}

struct point
{
    int num;
    int time;
    int left;

    bool operator<(const point &other) const
    {
        return time > other.time;
    }
};

//非最优版本
int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {
    memset(head,-1,sizeof(head));
    Cnt=0; //注意大小写
    int n=charge.size();
    for(const auto &edge:paths){
        addEdge(edge[0],edge[1],edge[2]);
        addEdge(edge[1],edge[0],edge[2]);
    }
    vector<vector<bool>> visited(n,vector<bool>(cnt+1,false));
    vector<int> distance(n,INT_MAX);
    priority_queue<point> heap;

    heap.push({start,0,0});
    while(!heap.empty()){
        auto [num,t,l]=heap.top();
        heap.pop();
        if (num == end) return t;
        if(!visited[num][l]){
            visited[num][l]=true;
            distance[num]=min(distance[num],t);
            for(int e=head[num];e!=-1;e=nxt[e]){
                if(l>=weight[e] && !visited[to[e]][l-weight[e]]){
                    heap.push({to[e],t+weight[e],l-weight[e]});
                }
            }
            if(l<cnt && !visited[num][l+1]){
                heap.push({num,t+charge[num],l+1});
            }
        }
    }
    return distance[end];
}

//best,二维dist数组,standard!!
//在优先队列（堆优化）实现的 Dijkstra 中，用 dist 数组取代 visited 数组是更标准、更健壮的写法。

int electricCarPlan_best(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {
    memset(head,-1,sizeof(head));
    Cnt=0; //注意大小写
    int n=charge.size();
    for(const auto &edge:paths){
        addEdge(edge[0],edge[1],edge[2]);
        addEdge(edge[1],edge[0],edge[2]);
    }
    vector<vector<int>> dist(n,vector<int>(cnt+1,INT_MAX));
    priority_queue<point> heap;

    dist[start][0]=0;
    heap.push({start,0,0});

    while(!heap.empty()){
        auto [num,t,l]=heap.top();
        heap.pop();
        if(t!=dist[num][l]) continue; //相当于visited剪枝
        if (num == end) return t; //提前返回
       
        for(int e=head[num];e!=-1;e=nxt[e]){
            int v=to[e],w=weight[e];
            if(l>=w){
                int nt=t+w,nl=l-w;
                if(nt<dist[v][nl]){
                    dist[v][nl]=nt;
                    heap.push({v,nt,nl});
                }
            }
        }

        if(l<cnt){
            int nt=t+charge[num],nl=l+1;
            if(nt<dist[num][nl]){
                dist[num][nl]=nt;
                heap.push({num,nt,nl});
            }
        }
    }
    return -1;
}