//岛屿数量（并查集做法）

#include<iostream>
#include<vector>
using namespace std;
const int MAXN=90001;

int father[MAXN];

int Size[MAXN];

int sets;

void build(int N)
{
    for(int i=0;i<N;i++){
        father[i]=i;
        Size[i]=1;
    }
    sets=N;
}

int find(int i) //递归版查找+扁平化
{
    if(i!=father[i]){
        father[i]=find(father[i]);
    }
    return father[i];
}

bool isSameSet(int x,int y)
{
    return find(x)==find(y);
}

void Union(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){ 
        father[fx]=fy;
        sets--;
    }
}

int numIslands(vector<vector<char>>& grid) {
    int m=static_cast<int>(grid.size());
    int n=static_cast<int>(grid[0].size());
    int lands=0;
    build(m*n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){ //注意是字符数组
                lands++;
                if(i-1>=0 && grid[i-1][j]=='1') Union(i*n+j,(i-1)*n+j);
                if(j-1>=0 && grid[i][j-1]=='1') Union(i*n+j,i*n+(j-1));
            }
        }
    }
    return sets-(m*n-lands);
}

//洪水填充做法

void dfs(vector<vector<char>>& grid,int i,int j)
{
    int m=static_cast<int>(grid.size());
    int n=static_cast<int>(grid[0].size());
    if(i<0 || j<0 || i==m || j==n || grid[i][j]!='1') return;
    grid[i][j]=0;
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
}

int numIslands2(vector<vector<char>>& grid) {
    int islands=0;
    int m=static_cast<int>(grid.size());
    int n=static_cast<int>(grid[0].size());
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                islands++;
                dfs(grid,i,j);
            }
        }
    }
    return islands;
}