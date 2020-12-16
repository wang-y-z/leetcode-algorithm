/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        traverse(res,tmp,root,sum);
        return res;
    }
    // void traverse(vector<vector<int>> &res ,vector<int> tmp,TreeNode* root, int sum){
    //     if(!root) return ;
    //     tmp.push_back(root->val);
    //     if(root->val == sum && !root->left &&!root->right ){
    //         res.push_back(tmp);
    //     }
    //     traverse(res,tmp,root->left,sum - root->val);
    //     traverse(res,tmp,root->right,sum - root->val);
    // }
    void traverse(vector<vector<int>> &res ,vector<int> &tmp,TreeNode* root, int sum){
        if(!root) return ;
        tmp.push_back(root->val);
        if(root->val == sum && !root->left &&!root->right ){
            res.push_back(tmp);
        }
        traverse(res,tmp,root->left,sum - root->val);
        traverse(res,tmp,root->right,sum - root->val);
        tmp.pop_back();
    }
    //细节!!!!!!
    //tmp如果传值才是对的，因为每次递归都是复制新的tmp数组；若传引用，则会保留每次递归之前所有路径上的节点值；
    //那么需要在递归之后tmp.pop_back();回溯清除这些数值；
};
// @lc code=end

