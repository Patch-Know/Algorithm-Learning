//水位上升的泳池中游泳

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int swimInWater(vector<vector<int>>& grid) {
    const int dir[5]={1,0,-1,0,1};
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
    typedef pair<int,pair<int,int>> PIP;
    priority_queue<PIP,vector<PIP>,greater<PIP>> heap;
    dist[0][0]=grid[0][0];
    heap.push({dist[0][0],{0,0}});
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
                int distance=max(d,grid[nx][ny]);
                if(distance<dist[nx][ny]){
                    dist[nx][ny]=distance;
                    heap.push({distance,{nx,ny}});
                }
            }
        }
    }
    return dist[m-1][n-1];
}