//打砖块
/*
1)炮弹打到的位置减1
2)天花板洪水填充，设置为2
3)时光倒流，炮弹打的位置+1，如果周围有2的位置，洪水填充，设置为2
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dfs(vector<vector<int>>& grid,int i,int j){
    int m=static_cast<int>(grid.size());
    int n=static_cast<int>(grid[0].size());
    if(i<0 || j<0 || i==m || j==n || grid[i][j]!=1) return 0;
    grid[i][j]=2;
    return 1+dfs(grid,i+1,j)+ dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1);
}

vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    int m=static_cast<int>(grid.size());
    int n=static_cast<int>(grid[0].size());
    for(const auto & pos : hits){
        grid[pos[0]][pos[1]]--;
    }
    for(int j=0;j<n;j++){
        dfs(grid,0,j);
    }
    vector<int> ans;
    for(auto it=hits.crbegin();it!=hits.crend();it++){
        int i=(*it)[0];
        int j=(*it)[1];
        grid[i][j]++;
        if(grid[i][j]==1 &&
            (i==0 || //天花板当然粘着
             (i-1>=0 && grid[i-1][j]==2) ||
             (i+1<m && grid[i+1][j]==2) ||
             (j-1>=0 && grid[i][j-1]==2) ||
             (j+1<n && grid[i][j+1]==2))){
                ans.push_back(dfs(grid,i,j)-1);
        }else ans.push_back(0);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}