#include<iostream>

using namespace std;

const int MAXN=10;

int grid[MAXN][MAXN];

const int dir[4][2]{{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int cnt=1;
    for(int j=0;j<n;j++){
        grid[0][j]=cnt++;
    }
    int direction=0;
    int x=0,y=n-1;
    for(int k=n-1;k>0;k--){
        direction=(direction+1)%4;
        for(int step=0;step<k;step++){
            x+=dir[direction][0];
            y+=dir[direction][1];
            grid[x][y]=cnt++;
        }
        direction=(direction+1)%4;
        for(int step=0;step<k;step++){
            x+=dir[direction][0];
            y+=dir[direction][1];
            grid[x][y]=cnt++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            cout << grid[i][j] << ' ';
        }
        cout << grid[i][n-1] << '\n';
    }
}