#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    vector<long long> arr(n+1);
    vector<int> left(k);
    left[0]=1;
    long long cnt=0;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        arr[i]+=arr[i-1];
        cnt+=left[arr[i]%k];
        left[arr[i]%k]++;
    }    
    cout << cnt;
    

    return 0;
}