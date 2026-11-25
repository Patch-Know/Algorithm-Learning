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
    node(int v):val(v),l(nullptr),r(nullptr){}
};

int cnt;

void tree_build(const vector<int>& v,node * pn)
{
    int n=v.size();
    if(cnt+1>=n) return;
    if(v[++cnt]!=0){
    pn->l=new node(v[cnt]);
    tree_build(v,pn->l);}
    if(cnt+1>=n) return;
    if(v[++cnt]!=0){
    pn->r=new node(v[cnt]);
    tree_build(v,pn->r);}
}

bool find_sum(node *r,int target,int s)
{
    if(!r) return false;
    s+=r->val;
    if(s==target) return true;
    if(find_sum(r->l,target,s)) return true;
    if(find_sum(r->r,target,s)) return true;
    return false;
}

int main()
{
    string s;
    int target;
    getline(cin,s);
    cin >> target;
    istringstream sin(s);
    vector<int> v;
    copy(istream_iterator<int>(sin),istream_iterator<int>(),back_inserter(v));
    if(v.empty()){ cout << 0; return 0; }
    cnt=0;
    node * root= new node(v[0]);
    tree_build(v,root);
    cout << (find_sum(root,target,0)?1:0);
}