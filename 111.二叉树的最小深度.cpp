/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    //01 dfs
    // int minDepth(TreeNode* root) {
    //     if( root == NULL) return 0;
    //     if( root->left == NULL && root->right == NULL )
    //         return 1;
    //     if( root->left == NULL )
    //         return minDepth(root->right)+1;
    //     if( root->right == NULL )
    //         return minDepth(root->left)+1;
    //     return min(minDepth(root->left),minDepth(root->right))+1;
    // }

    //02 bfs 20210117
    //depth 可以作为层序号存放，也可以在每次递增一层的时候去更新depth
    int minDepth( TreeNode* root ){
        if(!root) return 0;
        queue<pair<TreeNode*,int>> que;
        que.emplace(root,1);
        while(!que.empty()){
            TreeNode* cur = que.front().first;
            int depth = que.front().second;
            que.pop();
            if(!cur->left && !cur->right){
                return depth;
            }
            if(cur->left){
                que.emplace(cur->left,depth+1);
            }
            if(cur->right){
                que.emplace(cur->right,depth+1);
            }
            //如果depth不放pair跟que的node绑定在一起
            //就在这里更新
            // depth++;
        }
        return 0;
    }
};
// @lc code=end

