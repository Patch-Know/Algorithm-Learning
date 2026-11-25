#include<iostream>
#include<string>
using namespace std;

const int N=1e5;

char arr[N];

string s;

void tree_preorder(int pos)
{
    int n=s.size();
    if(pos>=n) return;
    if(s[pos]=='#') return;
    cout << s[pos];
    tree_preorder(pos*2+1);
    tree_preorder(pos*2+2);
}

int main()
{
    getline(cin,s);
    tree_preorder(0);
}