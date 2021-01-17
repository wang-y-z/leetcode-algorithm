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
    //01 取巧 ：利用前序遍历和不定长的vector根据depth来pushback
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> res;
    //     tranverse(root , 0 , res);
    //     return res;
    // }
    // void tranverse( TreeNode *root, int count ,vector<vector<int>> &res ){
    //     if( !root  ) return ;
    //     if( count >= res.size() )
    //         res.push_back( vector<int> {} );
    //     res[count].push_back(root->val);
    //     tranverse(root->left , count +1 , res);
    //     tranverse(root->right , count +1 , res);
    // }

    //02 标准层序遍历 queue
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        vector<vector<int>> res;
        while( !q.empty() ){
            int sz = q.size();
            vector<int> vec;
            for(int i = 0 ; i < sz ; i++){
                TreeNode * node = q.front();
                q.pop();
                vec.push_back( node->val );
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
    
};
// @lc code=end

