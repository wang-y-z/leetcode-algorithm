/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string t) {
        unordered_map<char, int> need,window;
        int left = 0;
        int right = 0;
        int valid = 0;
        vector<int> start ;

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
                if(valid == need.size()){
                    start.push_back(left);
                };
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
        return start;
    }
};
// @lc code=end

