/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size());
        stack<int> st;
        for( int i = 0; i < T.size() ; ++i ){
            while( !st.empty() ){
                int index = st.top();
                if( T[index] >= T[i] ){
                    break;
                }
                st.pop();
                res[index] = i - index;
            }
            st.push( i );
        }
        return res;
    }
};
// @lc code=end

