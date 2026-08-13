//二叉搜索树的最近公共祖先

#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==p || root==q || (root->val>p->val&&root->val<q->val) || (root->val<p->val&&root->val>q->val)) return root;
    if(root->val>p->val&&root->val>q->val) return lowestCommonAncestor(root->left,p,q);
    return lowestCommonAncestor(root->right,p,q);
}

//也可以不用递归

TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    while(root->val!=p->val && root->val!=q->val){
        if(min(p->val,q->val)<root->val && root->val<max(p->val,q->val)) break;
        root=root->val<min(p->val,q->val) ? root->right : root->left;
    }
    return root;
}