/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    //01-递归
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     if( nums.empty()){
    //         return {{}};
    //     }
    //     int n = nums.back();
    //     nums.pop_back();
    //     vector<vector<int>> res =  subsets(  nums);
    //     int K = res.size();
    //     // for(int i = 0 ; i < res.size() ; i++){
    //     for(int i = 0 ; i < K ; i++){
    //         res.push_back(res[i]);
    //         res.back().push_back(n);
    //     }
    //     return res;
    // }
    //02-回溯
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        traverse(nums, 0 , track);
        return res;
    }
    void traverse(vector<int>& nums, int n ,vector<int>& track){
        res.push_back(track);
        for( int i = n ; i < nums.size() ; i++ ){
            track.push_back( nums[i] );
            traverse(nums,i+1,track);
            track.pop_back();
        }
    }
};
// @lc code=end

