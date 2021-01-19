/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if(s == t) return s;
        unordered_map<char, int> need,window;
        int left = 0;
        int right = 0;
        int valid = 0;
        int start = 0 , len = INT_MAX;

        for(auto c : t) need[c]++;
        while( right < s.size() ){
            char c = s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]){//这样才能包含重复字符的情况；
                    valid++;//valid记录：window里面,c是否存在;所以跟need.size挂钩
                }
            }
            while( valid == need.size() ){
                if(right-left < len){
                    start = left;
                    len = right - left;
                }
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
        return len == INT_MAX ? "" : s.substr(start,len);
    }
};
// @lc code=end

