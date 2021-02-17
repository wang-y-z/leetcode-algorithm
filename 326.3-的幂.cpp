/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        int a = pow(3,19);
        return n > 0 && a % n == 0;
    }
};
// @lc code=end

