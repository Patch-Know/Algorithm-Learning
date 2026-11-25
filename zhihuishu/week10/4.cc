//最大二叉树

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node{
    int val;
    node *l,*r;
    node(int v):val(v),l(nullptr),r(nullptr){}
};

void build_max(vector<int> &v,node *root,int l,int r,int m)
{
    if(l<=m-1){
        int max_pos=max_element(v.begin()+l,v.begin()+m)-v.begin();
        root->l=new node(v[max_pos]);
        build_max(v,root->l,l,m-1,max_pos);
    }
    if(r>=m+1){
        int max_pos=max_element(v.begin()+m+1,v.begin()+r+1)-v.begin();
        root->r=new node(v[max_pos]);
        build_max(v,root->r,m+1,r,max_pos);
    }
}

void preorder(node *root)
{
    if(!root) return;
    cout << root->val << ' ';
    preorder(root->l);
    preorder(root->r);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x:v) cin >> x;
    int max_pos=max_element(v.begin(),v.end())-v.begin();
    node *root=new node(v[max_pos]);
    build_max(v,root,0,n-1,max_pos);
    preorder(root);
}