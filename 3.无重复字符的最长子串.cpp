/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 01 双指针 hash表记录index 跳转left边界是关键
        // int l = 0, r = 0 , maxl = 0 , length = 0;
        // unordered_map<char, int> hash;
        // while( r<s.length() ){
        //     char tmpC = s[r];
        //     if( hash.find(tmpC) != hash.end() && hash[tmpC] >= l ){
        //         l = hash[tmpC] + 1;
        //         length = r - l;
        //     }
        //     hash[tmpC] = r;
        //     r++;
        //     length++;
        //     maxl = max( maxl, length );
        // }
        // return maxl;
        
    }
};
// @lc code=end

