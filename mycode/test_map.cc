#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<string,int> m;
    m["abc"]+=5;
    m["d"] = 2;
    for(auto x:m){
        cout << x.first << ": " << x.second << endl;
    }
    return 0;
}