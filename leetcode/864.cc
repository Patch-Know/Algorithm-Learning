// 获取所有钥匙的最短路径
// whole level pop
// 整层展开可以用l和r记录队列的范围,只用一个队列即可
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN=31;
const int MAXM=31;

bool visited[1<<6][MAXM][MAXN];
int g[MAXM][MAXN];

struct point
{
    int x,y;
    int info;
};

int shortestPathAllKeys(vector<string>& grid) {
    memset(visited,0,sizeof(visited));
    memset(g,0,sizeof(g));
    int m=grid.size();
    int n=grid[0].size();
    int startx,starty;
    int keynum=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            char ch=grid[i][j];
            if(ch=='.') g[i][j]=0;
            else if(ch=='#') g[i][j]=-1;
            else if(ch=='@'){
                g[i][j]=0;
                startx=i;
                starty=j;
            }else if(ch>='a' && ch<='f'){
                g[i][j]=1<<(ch-'a');
                keynum++;
            }else{
                g[i][j]=64+(ch-'A');
            }
        }
    }
    int allkey=(1<<keynum)-1;
    queue<point> curLevel,nxtLevel;
    int level=0;
    const int dir[5]={1,0,-1,0,1};
    curLevel.push({startx,starty,0});
    visited[0][startx][starty]=true;
    while(!curLevel.empty()){ //level 表示处理哪一"层"的点,也就是走了几步
        while(!curLevel.empty()){
            auto [x,y,info]=curLevel.front();
            curLevel.pop();
            if(info==allkey) return level;
            for(int i=0;i<4;i++){
                int nx=x+dir[i];
                int ny=y+dir[i+1];
                if(nx<0 || nx>=m || ny<0 || ny>=n || g[nx][ny]==-1) continue;
                if(g[nx][ny]<64){
                    int n_info=info | g[nx][ny];
                    if(visited[n_info][nx][ny]) continue;
                    visited[n_info][nx][ny]=true;
                    nxtLevel.push({nx,ny,n_info});
                }else{
                    if(visited[info][nx][ny]) continue;
                    int lock=1<<(g[nx][ny]-64);
                    if(info & lock){
                        visited[info][nx][ny]=true;
                        nxtLevel.push({nx,ny,info});
                    }
                }
            }
        }
        curLevel.swap(nxtLevel);
        nxtLevel={};
        level++;
    }
    return -1;
}

int main()
{
    vector<string> temp={"@..aA","..B#.","....b"};
    cout << shortestPathAllKeys(temp);
}