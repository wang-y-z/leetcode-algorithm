/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
// 01 直接反转再赋值
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(auto &v : matrix){
            reverse(v.begin(),v.end());
        }       
        int tmp = 0;
        int N = matrix.size();
        for(int i = 0 ; i < N ; i ++){
            for( int j = 0 ; j < N - i ; j++ ){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[N - 1 - j][N- 1 - i];
                matrix[N - 1 - j][N- 1 - i] = tmp;
                // cout<< "i  j"<< i<< " "<< j << " "<<matrix[i][j] <<endl;
            }
        }
    }
    //02 也可以使用temp一口气原地把四个元素互换位置
    
};
// @lc code=end

