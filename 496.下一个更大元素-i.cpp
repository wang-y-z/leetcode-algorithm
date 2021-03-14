/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size() , -1);
        stack<int> st;
        unordered_map<int,int> dic;
        for(int i = 0 ; i < nums1.size() ; i++){
            dic[nums1[i]] = i;
        }
        for(auto &num : nums2){
            while( !st.empty() && st.top() < num ){
                int cur = st.top();
                if( dic.count(cur) ){
                    res[dic[cur]] = num;
                }
                st.pop();
            }
            st.push(num);
        }
        return res;
    }
};
// @lc code=end

