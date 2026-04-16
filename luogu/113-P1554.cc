#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    vector<int> arr(10,0);
    for (int i=a;i<=b;i++){
        int temp=i;
        arr[temp%10]++;
        while (temp/=10)
        {
            arr[temp%10]++;
        }
    }
    for(int x:arr) cout<<x<<' ';
    return 0;
}