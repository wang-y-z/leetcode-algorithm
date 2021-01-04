/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int count = 0;
        int start = 0;
        for(int i = 1 ; i<s.length();i++){
            if(s[i-1] == s[i] ){
                count++;
                if(count>=2&&i==s.length()-1){
                    res.push_back({start,start+count});
                }
            }else{
                if(count>=2){
                    res.push_back({start,start+count});
                    start = i;
                    count = 0;
                }else{
                    start = i;
                    count = 0;    
                }
            }
        }    
        return res;
    }
};
// @lc code=end

