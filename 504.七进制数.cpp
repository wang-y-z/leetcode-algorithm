/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        bool flag = true;
        if(num<0){
            flag = false;
            num = -num;
        }
        string res;
        int a = 0;
        int b = 0;
        while( num ){
            a = num / 7;
            b = num % 7;
            res = to_string( b ) + res;
            num = a;
        }
        return flag ?res :  "-"+res;
    }
};
// @lc code=end

