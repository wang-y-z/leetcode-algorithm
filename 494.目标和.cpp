/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    //面试要体现思路的优化过程
    //1.暴力：直接对每种情况进行求和
    //2.dfs回溯：判断最底层时和是否为target
    //3.动态规划：转换为01背包：求nums中找数据凑成(sum+target)/2的组合
        //组合和排列是两种经典题型
    int res;
    int findTargetSumWays(vector<int>& nums, int S) {
        traverse(nums, S, 0);
        return res;
    }
    void traverse( vector<int>& nums, long S, int depth ){ // 细节，这里int会溢出。因为sum在过程中可能很大
        if(depth == nums.size()){
            if(S == 0){
                res++;
            }
            return ;
        }
        // std::cout<< depth <<std::endl;
        // S += nums[depth];
        traverse( nums, S + nums[depth], depth+1);
        // S -= nums[depth];

        // S -= nums[depth];
        traverse( nums, S - nums[depth], depth+1);
        // S += nums[depth];
    }
};
// @lc code=end

