//最小体力消耗路径
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    const int dir[5]={1,0,-1,0,1};
    int m=heights.size();
    int n=heights[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
    typedef pair<int,pair<int,int>> PIP;
    priority_queue<PIP,vector<PIP>,greater<PIP>> heap;
    dist[0][0]=0;
    heap.push({0,{0,0}});
    while(!heap.empty()){
        auto [d,p]=heap.top();
        auto [x,y]=p;
        heap.pop();
        if(!visited[x][y]){
            visited[x][y]=true;
            for(int i=0;i<4;i++){
                int nx=x+dir[i];
                int ny=y+dir[i+1];
                if(nx<0 || nx>=m || ny<0 || ny>=n || visited[nx][ny]) continue;
                int distance=max(d,abs(heights[x][y]-heights[nx][ny]));
                if(distance<dist[nx][ny]){
                    dist[nx][ny]=distance;
                    heap.push({distance,{nx,ny}});
                }
            }
        }
    }
    return dist[m-1][n-1];
}

int main()
{
    vector<vector<int>> temp={{1,2,2},{3,8,2},{5,3,5}};
    int ans=minimumEffortPath(temp);
    cout << ans;
}