//地图分析
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Point
{
    int x,y,dist;
};


int maxDistance(vector<vector<int>>& grid) {
    int n=grid.size();
    int cnt=0;
    vector<Point> que(n*n);
    int l=0,r=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                cnt++;
                que[r++]={i,j,0};
            }
        }
    }
    if(cnt==0 || cnt==n*n) return -1;
    int ans=0;
    while(l<r){
        auto [x,y,d]=que[l++];
        ans=max(ans,d);
        //grid[x][y]=1;应该在入队时标记为已访问！！避免重复入队！！
        if(x-1>=0 && grid[x-1][y]==0){
            que[r++]={x-1,y,d+1};
            grid[x-1][y]=1;
        } 
        if(x+1<n && grid[x+1][y]==0){
            que[r++]={x+1,y,d+1};
            grid[x+1][y]=1;
        } 
        if(y-1>=0 && grid[x][y-1]==0){
            que[r++]={x,y-1,d+1};
            grid[x][y-1]=1;
        } 
        if(y+1<n && grid[x][y+1]==0){
            que[r++]={x,y+1,d+1};
            grid[x][y+1]=1;
        } 
    }
    return ans;
}