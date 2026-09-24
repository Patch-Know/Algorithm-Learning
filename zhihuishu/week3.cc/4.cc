//最大子序列问题

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    
    int res=0;
    int sum=0;

    int num;
    for(int i=0;i<k;i++){
        cin >> num;
        sum+=num;
        if(sum<0) sum=0;
        else res=max(res,sum);
    }

    cout << res;
}