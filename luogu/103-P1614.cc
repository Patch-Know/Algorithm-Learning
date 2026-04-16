#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int min,sum;
    sum=accumulate(v.begin(),v.begin()+m,0);
    min=sum;
    for (int i = 1; i < n-m+1; i++)
    {
        sum+=v[i+m-1]-v[i-1];
        if(sum<min) min=sum;
    }
    cout << min;
    
    return 0;
}