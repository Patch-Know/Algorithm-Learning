#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int a[] = {0,1,1,2,3,5,8,13,21,55,89};
    list<int> l;
    vector<int> v;
    l.assign(begin(a),end(a));
    v.assign(begin(a),end(a));
    auto itl = l.begin();
    while(itl!=l.end()){
        if(*itl%2){
            itl=l.erase(itl);
        }else itl++;
    }
    auto itv = v.begin();
    while(itv!=v.end()){
        if(*itv%2==0){
            itv=v.erase(itv);
        }else itv++;
    }
    for(auto x:l) cout << x << endl;
    cout << endl;
    for(auto x:v) cout << x << endl;

    return 0;
}