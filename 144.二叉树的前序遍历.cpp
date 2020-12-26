/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    void tranverse(TreeNode *cur,vector<int> &vec){
        if(cur == NULL) return;
        vec.push_back(cur->val);
        tranverse(cur->left,vec);
        tranverse(cur->right,vec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        tranverse(root,result);
        return result;
    }
};
// @lc code=end

