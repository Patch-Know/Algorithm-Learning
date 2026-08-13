//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void f(TreeNode* node,int target,int sum,vector<vector<int>> &ans,vector<int> &path)
{
    path.push_back(node->val);
    if(!node->left && !node->right){
        if(sum+node->val==target) ans.push_back(path);
    }else{
        if(node->left) f(node->left,target,sum+node->val,ans,path);
        if(node->right) f(node->right,target,sum+node->val,ans,path);
    }
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if(!root) return {};
    vector<vector<int>> ans;
    vector<int> path;
    f(root,targetSum,0,ans,path);
    return ans;
}