/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //判断边界
        if(intervals.empty()) {return 0;}
        sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){
            return a[1]<b[1];
        });
        int num = 0 ;
        int p = intervals[0][1];
        for(int i = 1 ; i < intervals.size() ; i++ ){
            if( intervals[i][0] < p ){
                num++;
            }else{
                p = intervals[i][1];
            }
        }
        return num;
    }
};
// @lc code=end

