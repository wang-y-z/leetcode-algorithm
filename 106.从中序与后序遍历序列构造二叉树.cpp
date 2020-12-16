/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
        // 01 每次递归创建vector
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            if(postorder.size() == 0) return NULL;
            int rootV = postorder[postorder.size() - 1];
            TreeNode* root = new TreeNode(rootV);
            int i ;
            for( i = 0 ; i < postorder.size() ; i ++){
                if(inorder[i] == rootV)
                {
                    break;
                }
            }
            vector<int> inorder_left(inorder.begin(), inorder.begin()+i);
            vector<int> inorder_right(inorder.begin()+i+1, inorder.end());
            // postorder.resize(postorder.size() - 1);
            vector<int> postorder_left(postorder.begin(), postorder.begin()+inorder_left.size());
            vector<int> postorder_right(postorder.begin()+inorder_left.size(), postorder.end() - 1 );
            root->left = buildTree(inorder_left, postorder_left);
            root->right = buildTree(inorder_right, postorder_right);
            return root;
        }
        // 02 使用索引减少这个开销 即不创建新的数组，而是根据循环不变特性来使用分割的int 标志位
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            if(postorder.size() == 0) return NULL;
            return traver(inorder , postorder,0,inorder.size(),0 , postorder.size());
        }
        TreeNode* traver( vector<int> & inorder , vector<int> & postorder, int in_l , int in_r , int po_l , int po_r){
            if (po_l == po_r) return NULL;
            int rootV = postorder[po_r - 1];
            TreeNode* root = new TreeNode(rootV);
            int i;

            for(i = in_l ; i< in_r ; i++){
                if(inorder[i] == rootV) break;
            }
            int leftInorder_l = in_l;
            int leftInorder_r = i;
            int rightInorder_l = i+1;
            int rightInorder_r = in_r;
            
            int  leftPostorder_l = po_l;
            int  leftPostorder_r = po_l + ( i - in_l )  ;
            int rightPostorder_l = po_l + ( i - in_l );
            int rightPostorder_r = po_r - 1;
            
            root->left = traver(inorder, postorder,leftInorder_l,leftInorder_r,leftPostorder_l,leftPostorder_r);
            root->right = traver(inorder, postorder,rightInorder_l,rightInorder_r,rightPostorder_l,rightPostorder_r);
            return root;
        }
};
// @lc code=end

