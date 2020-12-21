/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> twoSumTarget(
        vector<int>& nums, int start, int target) {
        // 左指针改为从 start 开始，其他不变
        int lo = start, hi = nums.size() - 1;
        vector<vector<int>> res;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            int left = nums[lo] , right = nums[hi];
            if(sum<target){
                while(lo<hi && nums[lo] == left) lo++;
            }else if(sum > target){
                while(lo<hi && nums[hi] == right) hi--;
            }else if(sum == target){
                res.push_back({left,right});
                while(lo<hi && nums[lo] == left) lo++;
                while(lo>hi && nums[hi] == right) hi--;
            }
        }
        return res;
    }
    /* 计算数组 nums 中所有和为 target 的三元组 */
    vector<vector<int>> threeSumTarget(vector<int>& nums, int start,int target) {
        // 数组排序——使之满足双指针遍历需求
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        // 穷举 threeSum 的每一个第一个数
        for (int i = start; i < n; i++) {
            // 对 target - nums[i] 计算 twoSum
            vector<vector<int>> 
                tuples = twoSumTarget(nums, i + 1, target - nums[i]);
            // 如果存在满足条件的二元组，再加上 nums[i] 就是结果三元组
            for (vector<int>& tuple : tuples) {
                tuple.push_back(nums[i]);
                res.push_back(tuple);
            }
            // 跳过第一个数字重复的情况，否则会出现重复结果
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 数组需要排序
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        // 穷举 fourSum 的第一个数
        for (int i = 0; i < n; i++) {
            // 对 target - nums[i] 计算 threeSum
            vector<vector<int>> 
                triples = threeSumTarget(nums, i + 1, target - nums[i]);
            // 如果存在满足条件的三元组，再加上 nums[i] 就是结果四元组
            for (vector<int>& triple : triples) {
                triple.push_back(nums[i]);
                res.push_back(triple);
            }
            // fourSum 的第一个数不能重复
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
    
};
// @lc code=end

