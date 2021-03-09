/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > result;
    vector<vector<int>> permute(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        //     do {
        //         result.push_back(nums);
        //     }while (next_permutation(nums.begin(), nums.end())); // 算法库的库函数 next_permutation
        //     return result;
        // }

        //dfs 回溯 深度优先，注意实现选择和撤销选择通过swap实现
        //swap本质就是：在某个depth进行选择，遍历一遍所有的可能性
        vector<vector<int>> res;
        dfs(nums,0,res);
        return res; 
    }
    
    void dfs(vector<int> &nums,int depth,vector<vector<int>> &res ){
        if( depth >= nums.size() - 1 ){
            res.push_back(nums);
            return;
        }
        for(int i = depth ; i < nums.size() ; i++){
            swap( nums[depth] , nums[i] );
            dfs(nums,depth+1,res);
            swap( nums[depth] , nums[i] );
        }
    }
};
// @lc code=end

