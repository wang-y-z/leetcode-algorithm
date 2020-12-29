/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */

// @lc code=start
// class Solution {
// public:
//     int minPatches(vector<int>& nums, int n) {
//         long curr_range  = 0;
//         int m = nums.size();
//         int res = 0;
//         for(long i = 1 , pos = 0 ; i <= n;){
//             if( pos >= m || i < nums[pos] ){
//                 res++;
//                 curr_range += i;
//             }else{
//                 curr_range += nums[pos];
//                 pos++;
//             }
//                 i = curr_range + 1;
//         }
        
//         return res;
//     }
// };

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int size = static_cast<int>(nums.size());
        int patches = 0, i = 0;
        long miss = 1;
        
        while (miss <= n) {
            if (i < size && nums[i] <= miss) // miss is covered
            {
                miss += nums[i++];
            }
            else  // patch miss to the array
            {
                miss += miss;
                patches++; // increase the answer
            }
        }
        return patches;
    }
};
// @lc code=end

