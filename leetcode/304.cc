#include<iostream>
#include<vector>

using namespace std;

const int MAXN=201;

int arr[MAXN][MAXN];

class NumMatrix {
private:
    int m;
    int n;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m=static_cast<int>(matrix.size());
        n=static_cast<int>(matrix[0].size());
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr[i+1][j+1]=matrix[i][j];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return arr[row2+1][col2+1]-arr[row1][col2+1]-arr[row2+1][col1]+arr[row1][col1];
    }
};