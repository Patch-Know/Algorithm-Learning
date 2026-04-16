#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v{1,3,5,6,2,4,9};
    v.erase(v.end(),v.end());
    for(int x:v) cout << x << endl;
    return 0;
}