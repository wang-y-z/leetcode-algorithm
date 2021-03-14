/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    // vector<int> nextGreaterElements(vector<int>& nums) {
    //     stack<int> stk;
    //     int count = 0;
    //     int n = nums.size();
    //     vector<int> res(n,-1);
    //     if(n == 1) return res;
    //     int i = 0;
    //     while( count <= n ){
    //         int k = i % n;
    //         while( !stk.empty() && nums[stk.top()] < nums[k] ){
    //             int cur = stk.top();
    //             stk.pop();
    //             res[cur] = nums[k];
    //             // cout<< cur<<" " << nums[k] <<endl;
    //             count++;  //这个地方判断条件有问题，不是靠填充数量终止的，而应该还是for,到点为止
    //         }
    //         // cout<< k <<endl;
    //         stk.push(k);
    //         i++;
    //     }
    //     return res;
    // }
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int count = 0;
        int n = nums.size();
        vector<int> res(n,-1);
        if(n == 1) return res;
        for( int i = 0 ; i < 2*n - 1 ; i++ ){
            int k = i % n; // 很关键的操作。循环就用取余就OK
            while( !stk.empty() && nums[stk.top()] < nums[k] ){
                int cur = stk.top();
                stk.pop();
                res[cur] = nums[k];
                count++;
            }
            stk.push(k);
            // i++;
        }
        return res;
    }
};
// @lc code=end

