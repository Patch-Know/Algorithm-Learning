//检查边长度限制的路径是否存在

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN=1e5+5;

int father[MAXN];

void build(int n)
{
    for(int i=0;i<n;i++){
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

void Union(int x,int y)
{
    father[find(x)]=find(y);
}

bool isSameSet(int x,int y)
{
    return find(x)==find(y);
}

//n是点的数量
//排序queries,防止超时
vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
    sort(edgeList.begin(),edgeList.end(),[](const auto &e1,const auto &e2){return e1[2]<e2[2];});
    // 给查询加上原始下标
    vector<vector<int>> qs;
    for (int i = 0; i < static_cast<int>(queries.size()); ++i) {
        qs.push_back({queries[i][0], queries[i][1], queries[i][2], i});
    }
    sort(qs.begin(), qs.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
    int cnt=static_cast<int>(queries.size());
    int m=static_cast<int>(edgeList.size());
    vector<bool> ans(cnt);
    build(n);
    int e=0;//边的编号
    for(const auto &q:qs){
        int u=q[0],v=q[1],limit=q[2],idx=q[3];
        for(;e<m && edgeList[e][2]<limit;e++){
            Union(edgeList[e][0],edgeList[e][1]);
        }
        ans[idx]=isSameSet(u,v)?true:false;
    }
    return ans;
}

