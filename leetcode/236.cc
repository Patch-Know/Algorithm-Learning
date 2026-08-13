//二叉树的最近公共祖先

#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root==p || root==q){
        return root;
    }
    TreeNode * l=lowestCommonAncestor(root->left,p,q);
    TreeNode * r=lowestCommonAncestor(root->right,p,q);
    if(l&&r) return root;
    if(!l&&!r) return NULL;
    return l ? l : r;
}