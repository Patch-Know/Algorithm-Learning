//到达角落需要移除障碍物的最小数目
//01bfs
//不需要visited标记#
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

struct Point
{
    int x,y;
};

int minimumObstacles(vector<vector<int>>& grid) {
    const int dir[5]={-1,0,1,0,-1};
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
    dis[0][0]=0;
    deque<Point> que;
    que.push_front({0,0});
    while(!que.empty()){
        auto [x,y]=que.front();
        que.pop_front();
        if(x==m-1 && y==n-1) return dis[m-1][n-1];
        for(int i=0;i<4;i++){
            int nx=x+dir[i];
            int ny=y+dir[i+1];
            if((nx>=0 && nx<m && ny>=0 && ny<n) && dis[x][y]+grid[nx][ny]<dis[nx][ny]){
                dis[nx][ny]=dis[x][y]+grid[nx][ny];
                if(grid[nx][ny]==0) que.push_front({nx,ny});
                else que.push_back({nx,ny});
            }
        }
    }
    return dis[m-1][n-1];
}
