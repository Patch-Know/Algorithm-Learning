//Flowerpot S

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

const int MAXN=1e5+5;

pair<int,int> arr[MAXN];
int q_max[MAXN];
int q_min[MAXN];
int lmax=0,rmax=0,lmin=0,rmin=0;

int N,D;

bool ok()
{
    int max_num=lmax<rmax?arr[q_max[lmax]].second:0;
    int min_num=lmin<rmin?arr[q_min[lmin]].second:0;
    return max_num-min_num>=D;
}

void push(int i)
{
    while(rmax-lmax>0 && arr[q_max[rmax-1]].second<=arr[i].second){
        rmax--;
    }
    q_max[rmax++]=i;
    while(rmin-lmin>0 && arr[q_min[rmin-1]].second>=arr[i].second){
        rmin--;
    }
    q_min[rmin++]=i;
}

void pop(int l)
{
    if(rmax>lmax && q_max[lmax]==l) lmax++;
    if(rmin>lmin && q_min[lmin]==l) lmin++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> D;

    for(int i=0;i<N;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr,arr+N);
    int min_width=INT_MAX;
    for(int l=0,r=0;l<N;l++){
        while(!ok() && r<N){
            push(r++);
        }
        if(ok()) min_width=min(min_width,arr[r-1].first-arr[l].first);
        pop(l);
    }

    if (min_width == INT_MAX) cout << -1;
    else cout << min_width;
}
