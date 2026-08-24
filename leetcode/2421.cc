//好路径的数目

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=3e4+1;

int father[MAXN];

int cnts[MAXN];

//int sets;

void build(int N)
{
    for(int i=0;i<N;i++){
        father[i]=i;
        cnts[i]=1;
    }
    //sets=N;
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

int Union(int x,int y,const vector<int>& vals)
{
    int fx=find(x);
    int fy=find(y);
    int path=0;//应该初始化！！
    if(fx!=fy){ 
        int maxx=vals[fx];
        int maxy=vals[fy];
        if(maxx>maxy){
            father[fy]=fx;
        }else if(maxx<maxy){
            father[fx]=fy;
        }else{
            path=cnts[fx]*cnts[fy];//注意加的顺序！！
            father[fy]=fx;
            cnts[fx]+=cnts[fy];
        }
        //sets--;
    }
    return path;
}

int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    int n=static_cast<int>(vals.size());
    build(n);
    sort(edges.begin(),edges.end(),[&](const auto &a,const auto &b)
    {return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]);});
    //注意[&]应用外部的局部变量！！应该比较值而不是索引!!
    int good=n;
    for(const auto & edge : edges){
        good+=Union(edge[0],edge[1],vals);
    }
    return good;
}