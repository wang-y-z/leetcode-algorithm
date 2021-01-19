/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string t, string s) {
        unordered_map<char, int> need,window;
        int left = 0;
        int right = 0;
        int valid = 0;
        // int start = 0 , len = INT_MAX;

        for(auto c : t) need[c]++;
        while( right < s.size() ){
            char c = s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]){
                    valid++;
                }
            }
            while( right - left >= t.size() ){//判断什么时候左侧收缩
                if(valid == need.size()) return true;
                char d = s[left];
                left++;
                if(need.count(d)){
                    if(window[d] == need[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return false;
    }
};
// @lc code=end

