#include<iostream>
#include<cmath>

using namespace std;

int a[1025][1025];

int main()
{
    int n;
    cin >> n;
    a[1][1]=1;

    for(int cnt=0;cnt<n;cnt++){
        int k=lround(pow(2,cnt));
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                a[i+k][j]=a[i][j];
                a[i][j+k]=a[i][j];
            }
        }
    }
    int m=lround(pow(2,n));
    for(int i=m;i>=1;i--){
        cout << a[i][m];
        for(int j=m-1;j>=1;j--){
            cout << ' ' << a[i][j] ;
        }
        puts("");
    }
    return 0;
}