#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int temp;
    while (cin >> temp && temp!=0)
    {
        v.push_back(temp);
    }
    reverse(v.begin(),v.end());
    for(int & x : v) cout << x <<' ';
    
    return 0;
}