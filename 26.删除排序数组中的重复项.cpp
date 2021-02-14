/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int size = nums.size();
//         int cnt = 0; 
//         for(int i=1; i<size; ++i){
//             if(nums[i] == nums[i-1])
//                 cnt++;
//             nums[i-cnt] = nums[i]; 
//         }
//         return size-cnt;
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //01
        // if(nums.size() == 0) return 0;
        // int l = 0 ;
        // int r = 1 ;
        // while(r < nums.size() ){
        //     if(nums[l] == nums[r] ){
        //         r++;
        //     }else{
        //         l++;
        //         nums[l] = nums[r];
        //     }
        // }
        // return l+1;

        if(nums.size() == 0){
            return 0 ;
        }
        int slow = 0  , fast = 0;
        while( fast<nums.size() ){
            if(nums[fast] != nums[slow]){
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};
// @lc code=end

