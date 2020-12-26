/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0) return res;
        vector<int> tmp={1};
        res.push_back(tmp);
        // if(numRows == 1){re}
        for(int i = 1 ; i< numRows ;i++){
            // tmp.push_back({1});
            gen(res,i+1);
        }
        return res;
    }
    void gen(vector<vector<int>> &res,int size){
        vector<int> back = res.back();
        back.push_back({0});
        vector<int> newVec = {1} ;
        // cout<<  "--"<<endl;
        for(int i =1 ; i< size;i++){
            newVec.push_back(back[i-1]+back[i]);
        }
        res.push_back(newVec);
    }
};
// @lc code=end

