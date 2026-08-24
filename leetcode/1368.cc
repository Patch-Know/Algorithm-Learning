//使网格图至少有一条有效路径的最小代价
//01bfs
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

struct Point
{
    int x,y;
};
/*
1:右
2:左
3:下
4:上
*/
int minCost(vector<vector<int>>& grid) {
    const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int m=grid.size();
    int n=grid[0].size(); 
    vector<vector<int>> cost(m,vector<int>(n,INT_MAX));
    cost[0][0]=0;
    deque<Point> que;
    que.push_front({0,0});
    while(!que.empty()){
        auto [x,y]=que.front();
        que.pop_front();
        if(x==m-1 && y==n-1) return cost[m-1][n-1];
        for(int i=0;i<4;i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            int d=i+1==grid[x][y]?0:1;
            if((nx>=0 && nx<m && ny>=0 && ny<n) && cost[x][y]+d<cost[nx][ny]){
                cost[nx][ny]=cost[x][y]+d;
                if(d==0) que.push_front({nx,ny});
                else que.push_back({nx,ny});
            }
        }
    }
    return cost[m-1][n-1];
}