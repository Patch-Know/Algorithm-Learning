// Prim算法模版（洛谷）
// 动态空间实现
// 时间复杂度O(n + m) + O(m * log m)

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> gragh(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        gragh[u].push_back({v,w});
        gragh[v].push_back({u,w});
    }
    typedef pair<int,int> pii;
    auto cmp=[](const pii &a,const pii &b){return a.second>b.second;};
    priority_queue<pii,vector<pii>,decltype(cmp)> heap(cmp);
    //选择最初节点
    for(const auto &edge:gragh[1]){
        heap.push(edge);
    }
    //哪些节点已经发现过了
    vector<bool> Set(n+1,false);
    Set[1]=true;
    int nodeCnt=1;//节点计数
    int ans=0;
    //主流程
    while(!heap.empty()){
        auto [next,cost]=heap.top();
        heap.pop();
        if(!Set[next]){
            Set[next]=true;
            nodeCnt++;
            ans+=cost;
            for(const auto &edge:gragh[next]){
                heap.push(edge);
            }
        }
    }
    if(nodeCnt==n) cout << ans; //注意prim算法统计点的个数
    else cout << "orz";
    return 0;
}