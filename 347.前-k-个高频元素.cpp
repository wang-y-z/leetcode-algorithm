/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //hash+优先队列
        //缺省情况下priority_queue利用max-heap（大顶堆）完
        //成对元素的排序，这个大顶堆是以vector为表现形式的
        //complete binary tree（完全二叉树）。
        vector<int> res;
        unordered_map<int, int> count;
        priority_queue<pair<int, int >> pq;//优先队列的应用
        for(auto n : nums){
            count[n]++;
        }
        for(auto p : count){
            pq.push(make_pair(-p.second, p.first));
            if(pq.size() > k) pq.pop();
        }
        while( k-- ){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

