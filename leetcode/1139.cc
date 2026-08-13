#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=101;

int arr[MAXN][MAXN];

class Solution {
private:
    int m;
    int n;
public:
    int sumRegion(int row1, int col1, int row2, int col2) {
        return arr[row2+1][col2+1]-arr[row1][col2+1]-arr[row2+1][col1]+arr[row1][col1];
    }

    int largest1BorderedSquare(vector<vector<int>>& grid) {
        m=static_cast<int>(grid.size());
        n=static_cast<int>(grid[0].size());
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr[i+1][j+1]=grid[i][j];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
            }
        }
        int width=0;
        for(int cnt=1;cnt<=min(m,n);cnt++){
            for(int i=0;i+cnt-1<m;i++){
                for(int j=0;j+cnt-1<n;j++){
                    if((cnt==1 && sumRegion(i,j,i,j)==1) ||
                        (cnt==2 && sumRegion(i,j,i+1,j+1)==4) ||
                        (cnt>2 && sumRegion(i,j,i+cnt-1,j+cnt-1)-sumRegion(i+1,j+1,i+cnt-2,j+cnt-2)==4*(cnt-1))){
                        width=cnt;
                    }
                }
            }
        }
        
        return width*width;
    }
    
};