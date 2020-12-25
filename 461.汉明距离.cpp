/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res  = 0;
        if(x==y) return res;
        while(x!=0 || y!= 0){
            if(x%2!=y%2)
                res++;
            x /= 2;
            y /= 2;
        }
        return res;
    }
};
// @lc code=end

