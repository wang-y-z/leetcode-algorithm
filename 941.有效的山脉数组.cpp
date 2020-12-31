/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() <3 ) return false;
        vector<int> res;
        int count = 0;
        for(auto i = 1 ; i<arr.size();i++){
            if( arr[i] == arr[i-1] ) return false;
            if( arr[i] < arr[i-1] ){
                count ++;
            }
        }
        for()
    }
};
// @lc code=end

