/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    class myQue {
    public: 
        deque<int> que;
        void pop( int v ){
            if(!que.empty() && que.front() == v){
                que.pop_front();
            }
        }
        void push( int v ){
            while( !que.empty() && v > que.back() ){
                que.pop_back();
            }
            que.push_back(v);
        }
        int front(){
            return que.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //01单调队列
        myQue q;
        vector<int> res;
        for( int i = 0 ; i < k ; i++ ){
            q.push(nums[i]);
        }
        res.push_back(q.front());
        for( int i = k ; i < nums.size() ; i++){
            q.pop( nums[i-k] );
            q.push( nums[i] );
            res.push_back( q.front() );
        }
        return res;
    }
};
// @lc code=end

