/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
//用记录表，非常精妙；
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26);
        bool used[26];
        memset(used,false,sizeof(used));
        string res = "";

        for(auto c : s){
            count[c-'a'] ++;
        }
        for(auto c : s){
            count[c-'a']--;
            if(used[c-'a']) continue;
            while( res.length()>0&& c < res[res.length()-1] && count[res[res.length()-1] - 'a']>0){
                used[res[res.length()-1] - 'a'] = false;
                res.erase(res.length()-1);
            }
            res += c;
            used[c-'a']=true;
        }
        return res;
    }
};
// @lc code=end

