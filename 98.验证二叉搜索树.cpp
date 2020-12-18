/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
//01   丑陋的提交
class Solution {
public:
    // bool f = false;
    vector<int> res;
    bool isValidBST(TreeNode* root) {
        tra(root);
        for(int i = 0; i< res.size()-1 ; i++ ){
            if(res[i]>=res[i+1]){
                return false;
            }
        }
        return true;
    }
    void tra(TreeNode* root){
        if( !root ) return ;
        tra(root->left);
        res.push_back(root->val);
        tra(root->right);
    }
};
// @lc code=end

