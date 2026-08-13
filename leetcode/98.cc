//验证二叉搜索树

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

bool is_search=true;

pair<int,int> tree_minmax(TreeNode* node)
{
    int tmin,tmax;
    if(node->left){
        auto [lmin,lmax]=tree_minmax(node->left);
        if(!is_search) return {0,0};
        if(lmax>=node->val){
            is_search=false;
            return {0,0};
        }
        tmin=lmin;
    }else tmin=node->val;
    if(node->right){
        auto [rmin,rmax]=tree_minmax(node->right);
        if(!is_search) return {0,0};
        if(rmin<=node->val){
            is_search=false;
            return {0,0};
        }
        tmax=rmax;
    }else tmax=node->val;
    return {tmin,tmax};
}

bool isValidBST(TreeNode* root) {
    tree_minmax(root);
    return is_search; 
}