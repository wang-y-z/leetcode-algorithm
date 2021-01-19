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
        
        //02 双指针 模板题；两层while 第一层移动右指针，第二层移动左指针；不管是
        //最大值还是最小值，只要保存就行；能遍历到所有的情况
        //最小子串的时候只需要记录一下最小值即可
        unordered_map<char, int> window;
        int left = 0;
        int right = 0;
        int res = 0;

        while( right < s.size() ){
            char c = s[right];
            right++;
            window[c]++;
            while( window[c] > 1 ){//判断什么时候左侧收缩
                char d = s[left];
                left++;
                window[d]--;
            }
            res  = max(res,right-left);
        }
        return res;
    }
};
// @lc code=end

