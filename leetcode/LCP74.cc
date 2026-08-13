//最强祝福力场
//离散化技巧，NB！！

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll; //数字大，开long long！！

const int MAXN=105;
ll diff[2*MAXN][2*MAXN];;
ll xs[2*MAXN];
ll ys[2*MAXN];

int Sort(ll arr[],int n)
{
    sort(arr,arr+n);
    int size=1;
    for(int i=1;i<n;i++){ //unique
        if(arr[i]!=arr[size-1]) arr[size++]=arr[i];
    }
    return size;
}

int Rank(ll arr[],ll v,int size)
{
    int l=0;
    int r=size-1;
    int m;
    int ans=0;
    while(l<=r){
        m=(l+r)/2;
        if(arr[m]>=v){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    return ans+1;
}

void add(int a, int b, int c, int d) 
{
    diff[a][b] += 1;
    diff[c + 1][d + 1] += 1;
    diff[c + 1][b] -= 1;
    diff[a][d + 1] -= 1;
}

int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
    for(int i=0;i<2*MAXN;i++){
        memset(diff[i],0,sizeof(diff[i]));
    }
    memset(xs,0,sizeof(xs));
    memset(ys,0,sizeof(ys));
    int n=static_cast<int>(forceField.size());
    ll x,y,r;
    for(int i=0,k=0,p=0;i<n;i++){
        x=forceField[i][0];
        y=forceField[i][1];
        r=forceField[i][2];
        xs[k++]=2*x-r;
        xs[k++]=2*x+r;
        ys[p++]=2*y-r;
        ys[p++]=2*y+r;
    }
    int sizex=Sort(xs,n*2);
    int sizey=Sort(ys,n*2);
    for(int i=0,a,b,c,d;i<n;i++){
        x=forceField[i][0];
        y=forceField[i][1];
        r=forceField[i][2];
        a=Rank(xs,2*x-r,sizex);
        b=Rank(ys,2*y-r,sizey);
        c=Rank(xs,2*x+r,sizex);
        d=Rank(ys,2*y+r,sizey);
        add(a,b,c,d);
    }
    ll ans=0;
    for(int i=1;i<sizex+2;i++){
        for(int j=1;j<sizey+2;j++){
            diff[i][j]+=diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
            ans=max(ans,diff[i][j]);
        }
    }
    return ans;
}