/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res = NULL;
    TreeNode* searchBST(TreeNode* root, int val) {
        return dfs(root,val);
        // return res;
    }
    TreeNode *dfs(TreeNode *root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;
        TreeNode *left_ret = nullptr, *right_ret = nullptr;
        if (root->left) left_ret = dfs(root->left, val);
        if (root->right) right_ret = dfs(root->right, val);
        return left_ret ? left_ret : right_ret ? right_ret : nullptr;
    }
};
// @lc code=end

