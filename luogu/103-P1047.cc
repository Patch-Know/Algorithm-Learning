#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,periods;
    cin >> n >> periods;
    vector<bool> v(n+1,true);
    int start,finish;
    for (int i = 0;i<periods;i++){
        cin >> start >> finish;
        for (int j=start;j<=finish;j++){
            v[j]=false;
        }
    }
    int sum=0;
    for(bool b:v) sum+= b==true? 1 : 0;
    cout << sum;
    return 0;
}