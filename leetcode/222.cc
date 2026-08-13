//完全二叉树的节点个数

#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int deep(TreeNode* root)
{
    int depth=0;
    while(root){
        depth++;
        root=root->left;
    }
    return depth;
}

int countNodes(TreeNode* root) {
    if(!root) return 0;
    int ld=deep(root->left);
    int rd=deep(root->right);
    int ans;
    if(ld==rd){
        ans=static_cast<int>(1u<<ld)+countNodes(root->right);
    }else{
        ans=static_cast<int>(1u<<rd)+countNodes(root->left);
    }
    return ans;
}