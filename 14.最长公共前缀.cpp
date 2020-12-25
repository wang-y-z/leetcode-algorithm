/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int n = strs.size();
        if(n==0) return "";
        for(int k = 0 ; k<strs[0].length() ; k++){
            char tmp = strs[0][k];
            for(int i = 1 ; i<n ; i++){
                if(strs[i].length() < k+1 ||  strs[i][k] != tmp) return res;    
            }
            res += tmp;
        }
        return res;
    }
};
// @lc code=end

