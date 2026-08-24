//最大人工岛

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(vector<vector<int>>& grid,int i,int j,int id)
{
    int m=static_cast<int>(grid.size());
    int n=static_cast<int>(grid[0].size());
    if(i<0 || j<0 || i==m || j==n || grid[i][j]!=1) return;
    grid[i][j]=id;
    dfs(grid,i+1,j,id);
    dfs(grid,i-1,j,id);
    dfs(grid,i,j+1,id);
    dfs(grid,i,j-1,id);
}

int largestIsland(vector<vector<int>>& grid) {
    int m=static_cast<int>(grid.size());
    int n=static_cast<int>(grid[0].size());
    int id=2;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                dfs(grid,i,j,id++);
            }
        }
    }
    vector<int> sizes(id,0);
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]>1){
                ans=max(ans,++sizes[grid[i][j]]);
            }
        }
    }
    vector<bool> visited(id,false);
    int up,down,left,right,merge;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                up=i-1>=0?grid[i-1][j]:0;
                down=i+1<m?grid[i+1][j]:0;
                left=j-1>=0?grid[i][j-1]:0;
                right=j+1<n?grid[i][j+1]:0;
                visited[up]=true;
                merge=1+sizes[up];
                if(!visited[down]){
                    merge+=sizes[down];
                    visited[down]=true;
                }
                if(!visited[left]){
                    merge+=sizes[left];
                    visited[left]=true;
                }if(!visited[right]){
                    merge+=sizes[right];
                    visited[right]=true;
                }
                ans=max(ans,merge);
                visited[up]=false;
                visited[down]=false;
                visited[left]=false;
                visited[right]=false;
            }
        }
    }
    return ans;
}