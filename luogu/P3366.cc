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