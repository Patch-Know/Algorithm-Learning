#include<iostream>
#include<string>
#include<sstream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int val;
    node *l,*r;
    node(char v):val(v),l(nullptr),r(nullptr){}
};

int cnt;

int degree2;

void tree_build(const string& s,node * pn)
{
    int n=s.size();
    if(cnt+1>=n) return;
    if(s[++cnt]!='#'){
        pn->l=new node(s[cnt]);
        tree_build(s,pn->l);
    }
    if(cnt+1>=n) return;
    if(s[++cnt]!='#'){
        pn->r=new node(s[cnt]);
        tree_build(s,pn->r);
    }
    if (pn->l != nullptr && pn->r != nullptr) {
        ++degree2;
    }
}

int main()
{
    string s;
    getline(cin,s);
    if(s.empty()){ cout << 0; return 0; }
    node * root= new node(s[0]);
    tree_build(s,root);
    cout << degree2;
}