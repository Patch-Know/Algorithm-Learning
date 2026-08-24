//被围绕的区域
//洪水填充，只感染边界区域
#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<char>>& board,int i,int j)
{
    int m=static_cast<int>(board.size());
    int n=static_cast<int>(board[0].size());
    if(i<0 || j<0 || i==m || j==n || board[i][j]!='O') return;
    board[i][j]='F';
    dfs(board,i+1,j);
    dfs(board,i-1,j);
    dfs(board,i,j+1);
    dfs(board,i,j-1);
}

void solve(vector<vector<char>>& board) {
    int m=static_cast<int>(board.size());
    int n=static_cast<int>(board[0].size());
    for(int i=0;i<m;i++){
        if(board[i][0]=='O') dfs(board,i,0);
        if(board[i][n-1]=='O') dfs(board,i,n-1);
    }
    for(int j=0;j<n;j++){
        if(board[0][j]=='O') dfs(board,0,j);
        if(board[m-1][j]=='O') dfs(board,m-1,j);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='O') board[i][j]='X';
            else if(board[i][j]=='F') board[i][j]='O';
        }
    }
}