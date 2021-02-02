/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand;
        int count = 0;
        for(auto n : nums){
            if(count == 0) cand = n;
            if(cand == n){
                count++;
            }else{
                count--;
            }
        }
        return cand;
    }
};
// @lc code=end

