/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         // k = k % nums.size();
//         // vector<int> res = vector<int>(nums.end() - k, nums.end());
//         // res.insert(res.end(), nums.begin(), nums.begin() + nums.size() - k);
//         // nums = res;

//         //环装旋转

//     }
// };


//8ms  简单优雅，三次reverse即可
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        k = k % N;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

//8ms 10MB
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {        
//         auto s = nums.size();
//         if (s < 2 || s == k) return;
//         k = k%s;

//         int swichTime = 0;
//         for (int r = 0; r < k && swichTime < s; r++) {
//             int temp = nums[r];  
//             int i = r+k;
//             do {   
//                 std::swap(temp, nums[i]);
//                 i = (i+k)%s;
//                 swichTime++;
//             } while (i != (r+k));
//         }
//     }
// };
// @lc code=end

