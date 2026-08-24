//2D trapRainWater

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct point
{
    int x,y;
};


int trapRainWater(vector<vector<int>>& heightMap) {
    int m=heightMap.size();
    int n=heightMap[0].size();
    typedef pair<int,point> PIP;
    auto cmp=[](const PIP &a,const PIP &b){return a.first>b.first;};
    priority_queue<PIP,vector<PIP>,decltype(cmp)> heap(cmp);
    vector<vector<bool>> visited(m,vector<bool>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==m-1 || j==0 || j==n-1){
                heap.push({heightMap[i][j],{i,j}});
                visited[i][j]=true;
            }else visited[i][j]=false;
        }
    }
    const int dir[5]={1,0,-1,0,1};
    int ans=0;
    while(!heap.empty()){
        auto [h,p]=heap.top();
        auto [x,y]=p;
        heap.pop();
        if(x>0&&x<m-1&&y>0&&y<n-1) ans+=max(0,h-heightMap[x][y]);
        for(int i=0;i<4;i++){
            int nx=x+dir[i];
            int ny=y+dir[i+1];
            if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny]){
                visited[nx][ny]=true;
                heap.push({max(h,heightMap[nx][ny]),{nx,ny}});
            }
        }
    }
    return ans;
}