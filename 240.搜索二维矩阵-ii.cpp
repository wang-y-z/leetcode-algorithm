/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // bool flag = false;
        if(matrix.size() == 0) return false;
        int i = 0;
        int j = matrix[0].size() - 1;
        while( i < matrix.size() && j >= 0 ){//j是闭区间是因为要包含列数为1的情况
            if( matrix[i][j] == target ){
                return true;
            }else if( matrix[i][j] > target ){
                --j;
            }else if(matrix[i][j] < target){
                ++i;
            }
        }
        return false;
    }
};
// @lc code=end

