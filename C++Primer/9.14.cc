#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v1{11,23,34,56,64};
    vector<int> v2{11,23,34,56,64};
    if (v1 == v2) cout << "Equal" << endl;
    else cout << "Not equal" << endl;
    return 0;
}