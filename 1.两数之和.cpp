/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> record;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int tmp=target-nums[i];
            if(record.find(tmp)!=record.end()){
                res.push_back(i);
                res.push_back(record[tmp]);
                break;
            }else
                record[nums[i]]=i;
        }
        return res;
    }
};
// @lc code=end

