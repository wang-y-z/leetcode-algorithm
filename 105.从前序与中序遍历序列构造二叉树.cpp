// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem105.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int i ;
        for( i = 0 ; i < preorder.size() ; i ++){
            if(inorder[i] == preorder[0])
            {
                break;
            }
        }
        vector<int> inorder_left(inorder.begin(), inorder.begin()+i);
        vector<int> inorder_right(inorder.begin()+i+1, inorder.end());
        vector<int> preorder_left(preorder.begin()+1, preorder.begin()+1+inorder_left.size());
        vector<int> preorder_right(preorder.begin()+1+inorder_left.size(), preorder.end());
        root->left = buildTree(preorder_left, inorder_left);
        root->right = buildTree(preorder_right, inorder_right);
        return root;
    }
};
// @lc code=end
