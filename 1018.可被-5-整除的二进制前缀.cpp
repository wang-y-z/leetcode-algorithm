/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res(A.size());
        int num = 0;
        for( int i = 0 ; i < A.size() ; i++ ){
            num <<= 1;
            num += A[i];
            num %= 10;
            res[i] = (num % 5 == 0);
        }
        return res;
    }
};
// @lc code=end

