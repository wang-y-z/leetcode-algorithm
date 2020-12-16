/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x<0 || x % 10 == 0 && x != 0 ){
//             return false;
//         }
//         else{
//             int r = 0;
//             while(r<x){    
//                 r = r * 10 + x % 10;
//                 x /= 10;
//                 }
//             return x == r || x == r / 10;
//         }
//     }
// };

class Solution {
public:
    bool isPalindrome(int x) {
        string  str = to_string(x);
        bool flag = true;
        for(int i=0,j=str.size()-1;i<=j;i++,j--){
            if(str[i]!= str[j]){
                flag = false;
                break;
            }
        }
        return flag;
    }
};
// @lc code=end

