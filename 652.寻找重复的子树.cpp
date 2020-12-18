/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
// 后序遍历，同时放在map计数即可输出重复的子树；
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string,int> map;
        dfs(root , res , map);
        return res;
    }
    string dfs(TreeNode* root , vector<TreeNode*> & res , unordered_map<string,int>& map){
        if(!root) return "#";
        string str = to_string(root->val) + ',' + dfs(root->left,res,map) + ',' + dfs(root->right,res,map);
        if(map[str] == 1){
            res.push_back(root);
        }
        map[str]++;
        // cout<< str <<endl;
        return str;
    }
};
// @lc code=end

