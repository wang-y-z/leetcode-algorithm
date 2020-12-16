/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //01 巧思：只有sum大于0时会考虑将sum纳入范围；如果sum为负数，说明这个部分会使得后面的部分
        //都降低；
        int ans = nums[0];
        int sum = 0;
        for(auto i : nums){
            if(sum > 0){
                sum += i;
            }else{
                sum = i;
            }
            ans = max(ans , sum);
        }
        return ans;
    }
};
// @lc code=end

