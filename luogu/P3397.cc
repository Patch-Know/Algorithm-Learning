//二维差分

#include<iostream>
#include<vector>

using namespace std;

const int MAXN=1005;

int arr[MAXN][MAXN];

void set(int x1,int y1,int x2,int y2)
{
    arr[x1][y1]+=1;
    arr[x1][y2+1]+=-1;
    arr[x2+1][y1]+=-1;
    arr[x2+1][y2+1]+=1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    int x1,y1,x2,y2;
    for(int i=0;i<m;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        set(x1,y1,x2,y2);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }    
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << arr[i][j] << ' ';
        }    
        cout << '\n';
    }
    return 0;
}