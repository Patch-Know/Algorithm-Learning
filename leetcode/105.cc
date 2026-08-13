//前序&中序遍历构造二叉树
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* f(vector<int>& preorder,int l1,int r1, vector<int>& inorder,int l2,int r2,unordered_map<int,int> & m)
{
    if(l1>r1) return nullptr;
    TreeNode* head=new TreeNode(preorder[l1]);
    if(l1==r1) return head;
    int k=m[preorder[l1]];
    head->left=f(preorder,l1+1,l1+1+k-1-l2,inorder,l2,k-1,m);
    head->right=f(preorder,r1+k+1-r2,r1,inorder,k+1,r2,m);
    return head;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> m;
    int b=static_cast<int>(inorder.size());
    for(int i=0;i<b;i++){
        m[inorder[i]]=i;
    }
    return f(preorder,0,b-1,inorder,0,b-1,m);
}