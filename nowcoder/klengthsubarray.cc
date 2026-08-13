#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

const int MAXN = 1e5+5;

int sum[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int,int> map; //sum->index
    map[0]=0;
    int N,k;
    cin >> N >> k;
    int ans=0;
    for(int i=0,num;i<N;i++){
        cin >> num;
        sum[i+1]=sum[i]+num;
        if(map.count(sum[i+1])==0) map[sum[i+1]]=i+1;
        if(map.count(sum[i+1]-k)!=0){
            ans=max(ans,i+1-map[sum[i+1]-k]);
        }
    }
    cout << ans;
    return 0;
}