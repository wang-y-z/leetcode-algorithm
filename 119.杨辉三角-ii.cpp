/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for(int i=0;i<rowIndex+1;++i){
            vector<int> above = res;
            for(int j=1;j<i;++j){
                res[j]=above[j-1]+above[j];
            }
            res.push_back(1);
        }
        return res;
    }
};
// @lc code=end

