/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
// class Solution {
// public:
//     int hash[26] ;
//     char findTheDifference(string s, string t) {    
//         // char res;
//         int count = 0;
//         for(auto i : s){
//             hash[(i - 'a')]++;
//         }
//         for(auto i : t){
//             hash[(i - 'a')]--;
//         }
//         for(auto i : hash){
//             if(i==-1) break;
//             count++;
//         }
//         return 'a'+count;
//     }
// };

// 02 牛逼，直接强制类型转换就行了
// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         int sum = 0;
//         for (auto i : t)
//             sum += i;
//         for (auto i : s)
//             sum -= i;
//         return sum;
//     }
// };

//03 lambda直接异或，本题直接化简为：s+t中，等价于2s+res字符，直接将
// 所有字符异或，剩下就是0异或res了；
class Solution {
public:
    // 屌丝版本
    // char findTheDifference(string s, string t) {
    //     char res=0;
    //     for(char& c:s+t) 
    //         res^=c;
    //     return res;
    // }
    // lambda表达式版本  hhhh
    char findTheDifference(string s, string t) {
        return [&]{ char res=0;for(char& c:s+t) res^=c;return res;}();
    }
};
// @lc code=end

