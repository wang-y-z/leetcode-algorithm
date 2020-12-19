// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem124.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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

//01 这个解法需要再细细思索一下
class Solution {
public:
    int maxPathSum(TreeNode* root , int &val) {
        if (!root) return 0;
        int left = maxPathSum(root->left,val);
        int right = maxPathSum(root->right,val);
        int mid = root->val + max(0,left) + max(0,right);
        int ret = root->val + max(0,max(left,right));
        val = max(val,max(ret,mid));
        return ret;
    }
    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        maxPathSum(root,val);
        return val;
    }
};
// @lc code=end

