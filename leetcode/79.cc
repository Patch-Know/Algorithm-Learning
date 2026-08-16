//单词搜索
//带路径的递归（无法改成动态规划）

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool f(vector<vector<char>>& board, string word,int i,int j,int pos)
{
    if(pos==(int)word.length()) return true;
    int m=board.size();
    int n=board[0].size();
    if(i<0 || j<0 || i>=m || j>=n || board[i][j]==0 || board[i][j]!=word[pos]) return false;
    char ch=board[i][j];
    board[i][j]=0;
    bool ans=f(board,word,i+1,j,pos+1)
            ||f(board,word,i-1,j,pos+1)
            ||f(board,word,i,j+1,pos+1)
            ||f(board,word,i,j-1,pos+1);
    board[i][j]=ch;
    return ans;
}

bool exist(vector<vector<char>>& board, string word) {
    int m=board.size();
    int n=board[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(f(board,word,i,j,0)) 
                return true;
        }
    }
    return false;
}