// 贴邮票
// 其实有静态数组节省内存的方法

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define PLUS

#ifndef PLUS
void set1(int x1,int y1,int x2,int y2,vector<vector<int>>& arr)
{
    arr[x1][y1]+=1;
    arr[x1][y2+1]-=1;
    arr[x2+1][y1]-=1;
    arr[x2+1][y2+1]+=1;
}

int regionSum(int x1,int y1,int x2,int y2,vector<vector<int>>& sum)
{
    return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
}

bool check(int x,int y,vector<vector<int>>& sum,int stampHeight, int stampWidth)
{
    return regionSum(x+1,y+1,x+stampHeight,y+stampWidth,sum)==0;
}

bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
    int m=static_cast<int>(grid.size());
    int n=static_cast<int>(grid[0].size());
    vector<vector<int>> arr(m+2,vector<int>(n+2,0));
    vector<vector<int>> sum(m+2,vector<int>(n+2,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum[i+1][j+1]=grid[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    for(int i=0;i+stampHeight-1<m;i++){
        for(int j=0;j+stampWidth-1<n;j++){
            if(check(i,j,sum,stampHeight,stampWidth)){
                set1(i+1,j+1,i+stampHeight,j+stampWidth,arr);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            arr[i][j]+=grid[i-1][j-1];
            if(arr[i][j]==0) return false;
        }
    }
    return true;
}

#else

const int MAXN=5e5+5;

int arr[MAXN];
int sum[MAXN];

void set2(int x1,int y1,int x2,int y2,int col)
{
    arr[x1*col+y1]+=1;
    arr[x1*col+y2+1]-=1;
    arr[(x2+1)*col+y1]-=1;
    arr[(x2+1)*col+y2+1]+=1;
}

int regionSum(int x1,int y1,int x2,int y2,int col)
{
    return sum[x2*col+y2]-sum[x2*col+y1-1]-sum[(x1-1)*col+y2]+sum[(x1-1)*col+y1-1];
}

bool check(int x,int y,int col,int stampHeight, int stampWidth)
{
    return regionSum(x+1,y+1,x+stampHeight,y+stampWidth,col)==0;
}

bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
    memset(arr, 0, sizeof(arr));
    memset(sum, 0, sizeof(sum));
    int m=static_cast<int>(grid.size());
    int n=static_cast<int>(grid[0].size());
    int col=n+2;
    // vector<vector<int>> arr(m+2,vector<int>(n+2,0));
    // vector<vector<int>> sum(m+2,vector<int>(n+2,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum[(i+1)*col+j+1]=grid[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            sum[i*col+j]+=sum[(i-1)*col+j]+sum[i*col+j-1]-sum[(i-1)*col+j-1];
        }
    }
    for(int i=0;i+stampHeight-1<m;i++){
        for(int j=0;j+stampWidth-1<n;j++){
            if(check(i,j,col,stampHeight,stampWidth)){
                set2(i+1,j+1,i+stampHeight,j+stampWidth,col);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            arr[i*col+j]+=arr[(i-1)*col+j]+arr[i*col+j-1]-arr[(i-1)*col+j-1];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            arr[i*col+j]+=grid[i-1][j-1];
            if(arr[i*col+j]==0) return false;
        }
    }
    return true;
}

#endif
int main()
{
    
    return 0;
}