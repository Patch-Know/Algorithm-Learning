//判断是否为降序数

#include<iostream>
#include<string>
using namespace std;

bool is_desend(string num)
{
    int len=num.length();
    for(int i=1;i<len;i++){
        if(num[i-1]<num[i]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n;
    getline(cin,n);
    cout << (is_desend(n)?1:0);
}