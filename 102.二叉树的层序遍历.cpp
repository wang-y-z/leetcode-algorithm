/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        tranverse(root , 0 , res);
        return res;
    }
    void tranverse( TreeNode *root, int count ,vector<vector<int>> &res ){
        if( !root  ) return ;
        if( count >= res.size() )
            res.push_back( vector<int> {} );
        res[count].push_back(root->val);
        tranverse(root->left , count +1 , res);
        tranverse(root->right , count +1 , res);
    }
};
// @lc code=end

