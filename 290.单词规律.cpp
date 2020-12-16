/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> str;
        string buf;
        stringstream is(s);
        while( is>> buf)
            str.push_back(buf);
        if(str.size() != pattern.length())
            return false;
        // for(auto i : str)
        //     cout<< i << ",";
        unordered_map<char,string> c2s;
        unordered_map<string,char> s2c;
        
        for(int i = 0 ; i < str.size() ; i++){
            char c = pattern[i];
            string s = str[i];
            if(c2s.find(c) != c2s.end()){
                string tempS = (c2s.find(c))->second;
                if(tempS != s) return false;
            }else if(s2c.find(s)!=s2c.end()){
                char tempC = (s2c.find(s))->second;
                if(tempC != c) return false;
            }
            c2s[c] = s;
            s2c[s] = c;
        }
        return true;
    }
};
// @lc code=end

