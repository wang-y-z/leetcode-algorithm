/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start

//TODO

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int num = 0;
        for( auto c : s ){
            if(c==' ') continue;
            if('0'<=c && c<='9'){
                num = num*10 + (c - '0');
                continue;
            }

        }
    }
};
// @lc code=end

