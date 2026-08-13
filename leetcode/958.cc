//判断完全二叉树

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

bool isCompleteTree(TreeNode* root) {
    const int max_nodes=105;
    TreeNode* nq[max_nodes];
    int l=0,r=0;
    nq[r++]=root;
    bool leaf=false;
    TreeNode* h;
    while(l<r){
        h=nq[l++];
        if((!h->left && h->right) || (leaf && (h->left || h->right))){
            return false;
        }
        if(h->left) nq[r++]=h->left;
        if(h->right) nq[r++]=h->right;
        if(!h->left || !h->right) leaf=true;
    }
    return true;
}