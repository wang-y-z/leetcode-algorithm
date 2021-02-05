/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        //01 普通二叉树的求个数方法
        // if(!root) return 0;
        // return 1+countNodes(root->left)+countNodes(root->right); 
        //02 满二叉树：直接数层数，pow(2,height)-1
        //03 完全二叉树：介于两者之间，而且其中至少包含一颗满二叉树；
        TreeNode* l = root;
        TreeNode* r = root;
        int hl = 0;
        int hr = 0;
        while( l ){
            l = l->left;
            hl++;
        }
        while( r ){
            r = r->right;
            hr++;
        }
        if(hl == hr){
            return (int)(pow(2,hl)-1);
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
// @lc code=end

