/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
// 使用栈来维护当前数字的正负，其实就是不断拆括号，再pop
class Solution {
public:
    int calculate(string s) {
        stack<int> sign;
        sign.push(1);
        int res = 0, num = 0, op = 1;
        for(auto c : s){
            if( c == ' ') continue;
            if('0'<=c && c<='9'){
                num = num *10 + (c - '0');
                continue;
            }
            res += op*num;
            num = 0;
            if(c == '+'){
                op = sign.top();
            }else if(c == '-'){
                op = -sign.top();
            }else if(c == '('){
                sign.push(op);
            }else if( c == ')'){
                sign.pop();
            }
        }
        res += op*num;
        return res;
    }
};
// @lc code=end

