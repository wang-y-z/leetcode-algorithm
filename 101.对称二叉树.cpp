/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isMirror(root->left, root->right);
    }
    bool isMirror( TreeNode* l , TreeNode* r ){
        if( l == NULL && r == NULL ) return true;
        if(l == NULL || r ==NULL ) return false;
        if(l->val != r->val) return false;
        return isMirror(l->left, r->right)&&isMirror(l->right , r->left);
    }
};
// @lc code=end

