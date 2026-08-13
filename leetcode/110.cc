//验证平衡二叉树

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height;

bool f(TreeNode * node){
    if(!node){
        height=0;
        return true;
    }
    int l,r;
    if(!f(node->left)) return false;
    l=height;
    if(!f(node->right)) return false;
    r=height;
    if(l-r>1 ||r-l>1) return false;
    height=max(l,r)+1;
    return true;
}

bool isBalanced(TreeNode* root) {
    return f(root);
}