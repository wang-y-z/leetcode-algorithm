/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_(nums);
        int l = 0 ;
        int r = nums.size() - 1;
        sort(nums.begin(),nums.end());
        // cout<< nums[l]<<nums[r]<<  nums_[l]<<nums_[r] <<endl;
        for( ; l<nums.size() ; l++){
            if(nums[l] != nums_[l]){
                break;
            }
        }
        for( ; r>=0;r--){
            if(nums[r] != nums_[r]){
                break;
            }
        }
        return (r-l+1 > 0 ? r-l+1 : 0);
    }
};
// @lc code=end

