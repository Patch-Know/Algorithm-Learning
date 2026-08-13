//二叉树的序列化和反序列化

#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//先序

// Encodes a tree to a single string.
string serialize1(TreeNode* root) {
    if(root==NULL) return "#,";
    return to_string(root->val)+","+serialize1(root->left)+serialize1(root->right);
}

// Decodes your encoded data to tree.
TreeNode* deserialize1(string data) {
    if(data=="#,") return NULL;
    stringstream ss(data);
    string temp;
    stack<pair<TreeNode *,int>> ns;
    getline(ss,temp,',');
    TreeNode * ans= new TreeNode(stoi(temp));
    ns.push({ans,0});
    while(getline(ss,temp,',')){
        // 修复：跳过末尾多余的空 token
        if (temp.empty()) continue;
        auto &node = ns.top(); //必须引用！！！
        if(temp=="#"){
            node.second++;
            if(node.second==2) ns.pop();
        }else{
            TreeNode * child = new TreeNode(stoi(temp));
            if(node.second==0){
                node.first->left=child;
                node.second++;
            }else{
                node.first->right=child;
                ns.pop();
            }
            ns.push({child,0});
        }
    }
    return ans;
}

//层序

// Encodes a tree to a single string.
string serialize2(TreeNode* root) {
    if(root==NULL) return "#,";
    string ans;
    queue<TreeNode *> nq;
    nq.push(root);
    ans+=to_string(root->val)+",";
    while(!nq.empty()){
        TreeNode * node=nq.front();
        nq.pop();
        if(node->left){
            ans+=to_string(node->left->val)+",";
            nq.push(node->left);
        }else ans+="#,";
        if(node->right){
            ans+=to_string(node->right->val)+",";
            nq.push(node->right);
        }else ans+="#,";
    }
    return ans;
}

// Decodes your encoded data to tree.
TreeNode* deserialize2(string data) {
    if(data=="#,") return NULL;
    stringstream ss(data);
    string temp;
    queue<TreeNode *> nq;
    getline(ss,temp,',');
    TreeNode * ans= new TreeNode(stoi(temp));
    nq.push(ans);
    while(getline(ss,temp,',')){
        // 修复：跳过末尾多余的空 token
        if (temp.empty()) continue;
        auto node = nq.front(); 
        nq.pop();
        if(temp!="#"){
            node->left=new TreeNode(stoi(temp));
            nq.push(node->left);
        }
        getline(ss,temp,',');
        if(temp!="#"){
            node->right=new TreeNode(stoi(temp));
            nq.push(node->right);
        }
    }
    return ans;
}