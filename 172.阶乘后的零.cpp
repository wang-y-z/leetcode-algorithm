/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        //分解质因数后，只有2 5可以凑成0.而且2远远多于5，所以只需统计5的个数
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
// @lc code=end

