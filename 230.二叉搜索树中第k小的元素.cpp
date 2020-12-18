/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
//01 要保证递归函数的return 纯粹性；
class Solution {
public:
    int count = 0;
    int res = 0;
    int kthSmallest(TreeNode* root, int k) {
        tra(root,k);    
        return res;
    }
    void tra(TreeNode* root, int k){
        if(!root) return;
        tra(root->left, k);
        count ++;
        if(count == k) res = root->val;
        tra(root->right, k);
    }
};
// @lc code=end

