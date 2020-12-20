/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode* dfs(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int idx = l;
        for (int i = l + 1; i <= r; ++i)
            if (nums[i] > nums[idx]) idx = i;

        TreeNode* root = new TreeNode(nums[idx]);
        root->left = dfs(nums, l, idx - 1);
        root->right = dfs(nums, idx + 1, r);
        return root;
    }
};
// @lc code=end

