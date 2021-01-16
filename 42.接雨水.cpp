/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    //01 暴力搜索：只要遇到一个柱子就看左最大和右最大
    // int trap(vector<int>& height) {
    //     int size = height.size();
    //     int res = 0;
    //     for( int i = 0 ; i < size-1 ; i++){
    //         int lmax = 0;
    //         int rmax = 0;
    //         for(int j = i ; j < size  ; j++){
    //             rmax = max(rmax, height[j]);
    //         }
    //         for(int j = i ; j >= 0 ; j--){
    //             lmax = max(lmax, height[j]);
    //         }
    //         res += min(lmax,rmax) - height[i];
    //     }
    //     return res;
    // }
    //02 备忘录优化 很简单 看一下之前两重循环做了多少重复工作就行
    // int trap(vector<int>& height) {
    //     int size = height.size();
    //     if(size==0) return 0;
    //     int res = 0;
    //     vector<int> lmax(size), rmax(size);
    //     lmax[0] = height[0];
    //     rmax[size - 1] = height[size -1];
    //     //备忘录：记录某个i的两个最大值，记录左最大值要从左往右遍历
    //     for(int i = 1 ; i < size ; i++){
    //         lmax[i] = max(lmax[i-1], height[i]);
    //     }
    //     for(int j = size-2 ; j >= 0 ; j--){
    //         rmax[j] = max(rmax[j+1], height[j]);
    //     }
    //     for(int i = 0 ; i < size ; i++){
    //         res += min(lmax[i],rmax[i])-height[i];
    //     }
    //     return res;
    // }
    //03 双指针优化
    int trap( vector<int> &height ){
        if(height.empty()) return 0;
        int n = height.size();
        int lmax = height[0];
        int rmax = height[n-1];
        int left = 0;
        int res = 0;
        int right = n - 1;
        while( left <= right ){
            lmax = max(lmax , height[left]);
            rmax = max(rmax , height[right]);
            if(lmax<rmax){
                res += lmax - height[left];
                left++;
            }else{
                res += rmax - height[right];
                right--;
            }
        }
        return res;
    }
};
// @lc code=end

