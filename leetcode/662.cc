//二叉树最大宽度

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

int widthOfBinaryTree(TreeNode* root) {
    unsigned long long max_width = 0;               // 使用 unsigned long long
    queue<pair<TreeNode*, unsigned long long>> tq;  // 编号用 unsigned long long
    int cnt = 1, newput = 0;
    tq.push({root, 1ULL});                          // 初始编号 1ULL

    while (!tq.empty()) {
        bool has_node = false;
        unsigned long long l, r;                    // l, r 也用 unsigned long long
        while (cnt--) {
            auto a = tq.front();
            tq.pop();

            if (a.first->left) {
                tq.push({a.first->left, a.second * 2});      // 溢出是定义良好的（模 2^64）
                newput++;
            }
            if (a.first->right) {
                tq.push({a.first->right, a.second * 2 + 1});
                newput++;
            }

            if (has_node) r = a.second;
            else {
                has_node = true;
                l = r = a.second;
            }
        }
        cnt = newput;
        newput = 0;

        if (has_node) {
            unsigned long long width = r - l + 1;
            if (width > max_width) max_width = width;
        }
    }
    return (int)max_width;  // 答案在 32 位范围内，安全转换
}
