/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        // cout<< *stones.rbegin()<<" "<< *(stones.rbegin()+1)<<endl;
        int a , b;
        while(stones.size() > 1){
            sort(stones.begin(),stones.end());
            a =  *stones.rbegin();
            b = *(stones.rbegin()+1);
            stones.pop_back();
            stones.pop_back();
            if(a!=b){
                stones.push_back((int)(a-b));
            }
        }
        if(stones.size()==0){
            return 0;
        }
        return stones[0];
    }
};
// @lc code=end

