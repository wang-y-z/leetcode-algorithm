/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        string buf;
        reverse(s.begin(),s.end());
        stringstream is(s);
        is >> buf;
        return buf.length();
    }
};
// @lc code=end

