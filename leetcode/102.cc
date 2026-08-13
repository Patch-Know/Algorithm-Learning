//二叉树的层序遍历

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    if(root==nullptr) return {};
    vector<vector<int>> ans;
    vector<int> temp;
    queue<TreeNode *> tq;
    int cnt=1,newput=0;
    tq.push(root);
    while(!tq.empty()){
        while(cnt--){
            TreeNode *a=tq.front();
            tq.pop();
            temp.push_back(a->val);
            if(a->left){
                tq.push(a->left);
                newput++;
            }
            if(a->right){
                tq.push(a->right);
                newput++;
            }
        }
        ans.push_back(temp);
        temp.clear();
        cnt=newput;
        newput=0;
    }
    return ans;
}