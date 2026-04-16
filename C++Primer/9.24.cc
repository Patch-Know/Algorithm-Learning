#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v;
    int a=1;
    // a=v[0];
    // a=v.at(0);
    // a=v.front();
    a=*(v.begin());
    cout << a << 100;
    return 0;
}