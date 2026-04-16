#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;

int main()
{
    vector<string> v0;
    list<const char *> v1{"hehedaren","mydearmum","cuterabbit"};
    v0.assign(v1.begin(),v1.end());
    for(string & x : v0) cout << x <<endl;

    return 0;
}