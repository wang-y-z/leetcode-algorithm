/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    vector<int> stack;
    int fib(int n) {
        stack.push_back(n);
        return fib(n-1)+stack.back();
    }
};
// @lc code=end

