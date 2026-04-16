#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    int chan = n;
    while (chan > 1)
    {
        v.push_back(chan);
        if(chan%2==0) chan/=2;
        else{
            chan*=3;
            chan++;
        }
    }
    v.push_back(1);
    for (auto i = v.rbegin();i!=v.rend();i++) cout << *i << ' ';
    
    return 0;
}