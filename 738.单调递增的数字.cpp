/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if(N<10) return N;
        string num_s = to_string( N );
        for( int i = num_s.length() - 2 ; i >= 0 ; i-- ){
            if(num_s[i] > num_s[i+1] ){
                num_s[i] -- ;
                for(int j = i + 1 ; j < num_s.length() ; j++){
                    num_s[j] = '9';
                }
            }
        }   
        return stoi(num_s);
    }
};
// @lc code=end

