/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
//我草真的牛逼这个解法这个思路；
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // if(s.length!=t.length) return false;
        if(s.size()==0&&t.size()==0) return true;
        for(int i =0 ; i<s.size();i++){
            if(s.find(s[i])!=t.find(t[i])){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

