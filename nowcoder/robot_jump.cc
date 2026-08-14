//机器人跳跃问题

#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN=1e5+5;

int arr[MAXN];

bool f(int E,int len,int max_height) //一定要设置最大高度，否则能量增长指数上升！！
{
    int cnt=0;
    while(cnt<len && (E>=arr[cnt+1] || E-(arr[cnt+1]-E)>=0)){ 
        if(E>=max_height) return true;
        E-=arr[++cnt]-E;
    }
    if(cnt==len) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int l=1,r=1,max_height=0;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        max_height=max(max_height,arr[i]);
    }
    r=max_height;
    int ans;
    while(l<=r){
        int m=(l+r)/2;
        if(f(m,N,max_height)){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    cout << ans;
    return 0;
}