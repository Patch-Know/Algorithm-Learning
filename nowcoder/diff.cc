//二维差分

#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

const int MAXN=1005;

ll arr[MAXN][MAXN];

ll init[MAXN][MAXN];

void set(ll x1,ll y1,ll x2,ll y2,ll k)
{
    arr[x1][y1]+=k;
    arr[x1][y2+1]-=k;
    arr[x2+1][y1]-=k;
    arr[x2+1][y2+1]+=k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> init[i][j];
        }    
    }
    ll x1,y1,x2,y2,k;
    for(int i=0;i<q;i++){
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        set(x1,y1,x2,y2,k);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }    
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << arr[i][j]+init[i][j] << ' ';
        }    
        cout << '\n';
    }
    return 0;
}