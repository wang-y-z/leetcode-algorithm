/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> sell(k+1,0);
        vector<int> buy(k+1,INT_MIN);
        for(auto &ele:prices)
        {
            for(int i=1;i<k+1;++i)
            {
                buy[i]=max(buy[i],sell[i-1]-ele);
                sell[i]=max(sell[i],buy[i]+ele);
            }
        }
        return sell[k];
    }
};
// @lc code=end

