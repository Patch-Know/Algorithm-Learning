//减少恶意软件的传播II

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=301;

int father[MAXN];

int Size[MAXN];

int bad_cnt[MAXN];

int source[MAXN];

void build(int N,const vector<int>& initial)
{
    for(int i=0;i<N;i++){
        father[i]=i;
        Size[i]=1;
    }
    memset(bad_cnt,0,sizeof(bad_cnt));
    for(int x:initial) bad_cnt[x]=1;
    memset(source,-1,sizeof(source));
}

int find(int i) 
{
    if(i!=father[i]){
        father[i]=find(father[i]);
    }
    return father[i];
}

bool isSameSet(int x,int y)
{
    return find(x)==find(y);
}

void normalUnion(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){ 
        father[fy]=fx;
        Size[fx]+=Size[fy];
    }
}

void specialUnion(int bad,int other)
{
    if(bad_cnt[other]!=0) return;
    int fo=find(other);
    if(source[fo]==-1){
        bad_cnt[bad]+=Size[fo];
        source[fo]=bad;
    }else if(source[fo]>=0 && source[fo]!=bad){
        bad_cnt[source[fo]]-=Size[fo];
        source[fo]=-2;
    }
}

int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    int n=static_cast<int>(graph.size());
    build(n,initial);
    for(int i=0;i<n;i++){
        if(bad_cnt[i]==0)
        for(int j=i+1;j<n;j++){
            if(bad_cnt[j]==0 && graph[i][j]==1) normalUnion(i,j);
        }
    }
    for(int i:initial){
        for(int j=0;j<n;j++){
            if(graph[i][j]==1)
            specialUnion(i,j);
        }
    }
    int ans=MAXN,cnt=0;
    for(int i:initial){
        if(bad_cnt[i]>cnt || (bad_cnt[i]==cnt && i<ans)){
            ans=i;
            cnt=bad_cnt[i];
        }
    }
    return ans;
}