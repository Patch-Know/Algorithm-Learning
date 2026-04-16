#include<iostream>
#include<vector>
#include<list>

using namespace std;

bool operator==(list<int>,vector<int>);

int main()
{
    list<int> v1{11,24,34,56,64};
    vector<int> v2{11,23,34,56,64};
    if (v1 == v2) cout << "Equal" << endl;
    else cout << "Not equal" << endl;
    return 0;
}

bool operator==(list<int> l,vector<int> v)
{
    if(l.size() == v.size()){
        vector<int> v2(l.begin(),l.end());
        return v2 == v;
    }
    return false;
}