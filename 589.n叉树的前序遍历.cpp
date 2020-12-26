/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        tra(root,res);
        return res;
    }
    void tra(Node* root,vector<int> &res){
        if(!root) return ;
        res.push_back(root->val);
        
        for(auto i : root->children){
            tra(i,res);
        }
    }
};
// @lc code=end

