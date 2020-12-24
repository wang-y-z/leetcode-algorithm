/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         sort(g.begin(),g.end());
//         sort(s.begin(),s.end());
//         int child =0; 
//         int cookie = 0;
//         while(child < g.size() && cookie < s.size()){
//             if ( g[child] <= s[cookie] ){
//                 child ++ ;
//                 cookie ++;
//             }
//         }
//         return child;
//     }
// };

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1; // 饼干数组的下表
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) {
            if (index >= 0 && s[index] >= g[i]) {
                result++;
                index--;
            }
        }
        return result;
    }
};
// @lc code=end

