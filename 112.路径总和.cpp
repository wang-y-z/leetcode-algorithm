/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int sum) {
        // 01 一行
        // return root && (( !root->left && !root->right && root->val==sum) || hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val));
        // 02 常规
        if(!root)
            return false;//因为最后是||所以可以这么写，即将所有根节点到叶子节点的判断结果都返回出来，最后看有没有true
        if(root->val==sum&&!root->left&&!root->right)//此时是叶子节点
            return true;
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};
// @lc code=end

