/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
// class Solution {
// public:
//     int index[10001] ;
//     vector<string> tmp = {"Gold Medal", "Silver Medal", "Bronze Medal"};
//     vector<string> findRelativeRanks(vector<int>& nums) {
//         vector<string> res;
//         for(int i = 0;i<nums.size();i++){
//             res.push_back(to_string(nums[i]));
//             index[nums[i]] = i+1;
//         }
//         int count = 0;
//         for(int i = 10000 ; i>0;i--){
//             if(index[i] != 0){
//                 if(count<3){
//                     res[index[i]-1] = tmp[count];
//                     count++;
//                 }else{
//                     res[index[i]-1] = to_string(++count);
//                 }
//             }
//         }
//         return res;

//     }
// };
//待做，看清题目最关键；这波首先看错题了，血亏
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> order;
        for(int i=0;i<nums.size();i++)
            order.push_back(i);
        sort(order.begin(),order.end(),[&nums](const int& a,const int& b){return nums[a]>nums[b];});
        vector<string> res(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            switch(i)
            {
                case 0:res[order[i]]="Gold Medal";break;
                case 1:res[order[i]]="Silver Medal";break;
                case 2:res[order[i]]="Bronze Medal";break;
                default:res[order[i]]=to_string(i+1);break;
            }
        }
        return res;
    }
};
// @lc code=end

