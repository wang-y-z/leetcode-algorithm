/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int l = 0 ; 
        int r = x ;
        if(x <= 1) return x;
        int res;
        while( l <= r ){
            long mid = (r + l )/ 2;
            if(mid*mid <= x){
                res = mid;
                l = mid+1;
            }else if( mid*mid > x ){
                r = mid-1;
            }
        }
        return res;
    }
};
// @lc code=end

