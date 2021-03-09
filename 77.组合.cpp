/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        traverse(n , k , track , 1);
        return res;
    }
    void traverse(int n , int k , vector<int>& track,int depth){
        if( k == track.size() ){
            res.push_back(track);
            return ;
        }
        for( int i = depth; i<= n; i++ ){
            track.push_back(i);
            traverse(n , k , track, i+1);
            track.pop_back();
        }
    }
};
// @lc code=end

