/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        deque<TreeNode*> Q;
        #define L2R false
        #define R2L true
        bool direction = L2R;

        Q.push_back(root);
        while (Q.size()) {
            int size = Q.size();
            vector<int> temp; temp.reserve(size);
            if (direction == L2R) {
                for_each(Q.begin(), Q.end(), [&temp](TreeNode* node){
                    temp.push_back(node->val);
                });
            }
            else { 
                for_each(Q.rbegin(), Q.rend(), [&temp](TreeNode* node){
                    temp.push_back(node->val);
                });
            }
            if (size) {
                direction = !direction;
                ans.push_back(temp);
            }

            while (size--) {
                TreeNode* curNode = Q.front();
                Q.pop_front();

                if (curNode->left ) Q.push_back(curNode->left);
                if (curNode->right) Q.push_back(curNode->right);
            }   
        }
        return ans;
    }
};
// @lc code=end

