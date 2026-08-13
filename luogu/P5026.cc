//输出格式
//一行 m 个整数，第 i 个整数表示 i 号位的水深。
//意味着数组从1到m位置输出，不是从0到m-1，build的时候也是依照输出
#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 1e6+1;

const int OFFSET = 3e4+1;

int arr[OFFSET+MAXN+OFFSET];

int n,m;

void build()
{
    for(int i=1;i<=m+OFFSET;i++){
        arr[i]+=arr[i-1];
    }
    for(int i=1;i<=m+OFFSET;i++){
        arr[i]+=arr[i-1];
    }
}

void set(int l,int r,int s,int e,int d)
{
    arr[l]+=s;
    arr[l+1]+=d-s;
    arr[r+1]-=d+e;
    arr[r+2]+=e;
}

void fall(int v,int x)
{
    set(x-3*v+OFFSET,x-2*v-1+OFFSET,0,v-1,1);
    set(x-2*v+OFFSET,x+OFFSET,v,-v,-1);
    set(x+1+OFFSET,x+2*v+OFFSET,-v+1,v,1);
    set(x+2*v+1+OFFSET,x+3*v+OFFSET,v-1,0,-1);
}

void show()
{
    for(int i=1+OFFSET;i<=m+OFFSET;i++){
        cout << arr[i] << ' ';
    }
}

int main()
{
    int v,x;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> v >> x;
        fall(v,x);
    }
    build();
    show();
    return 0;
}