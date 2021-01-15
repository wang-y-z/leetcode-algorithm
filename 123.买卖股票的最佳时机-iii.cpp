/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if( prices.size() == 0 ) return 0;
//         vector<vector<int>> dp(prices.size(),vector<int>(5,0) );
//         dp[0][0] = 0;
//         dp[0][1] = -prices[0];
//         dp[0][3] = -prices[0];
//         for(int  i = 1 ; i < prices.size() ; i++){
//             dp[i][0] = dp[i-1][0];
//             dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
//             dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
//             dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
//             dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
            
//         }
//         return dp[prices.size() - 1][4];
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1 = INT_MIN, s1 = 0, b2 = INT_MIN, s2 = 0;
        for (int p : prices) {
            b1 = max(b1, -p);
            s1 = max(s1, b1 + p);
            b2 = max(b2, s1 - p);
            s2 = max(s2, b2 + p);
        }
        return s2;
    }
};
// @lc code=end

