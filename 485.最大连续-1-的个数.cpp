/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int l = 0, r = 0;
        while(r<nums.size()){
            if( nums[r] == 1 ){
                ++r;
            }else{
                res = max(res,r-l);
                ++r;
                l = r;
            }
        }
        res = max(res,r-l);
        return res;
    }
};
// @lc code=end

