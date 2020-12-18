/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cur = 0;
    TreeNode* convertBST(TreeNode* root) {
        tra(root);
        return root;
    }
    void tra(TreeNode* root){
        if(!root) return;
        tra(root->right);
        cur += root->val;
        root->val = cur;
        tra(root->left);
    }
};
// @lc code=end

