/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    static bool cmp( int a , int b ){
        if(a == b) return true;
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        int i = 0;
        // cout<<s1<<" " <<s2<<endl;
        // cout<<s1<<" " <<s2<<endl;
        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i] < s2[i]){
                return false;
            }else if(s1[i]>s2[i]){
                return true;
            }
        }
        return true; 
    }
    string largestNumber(vector<int>& nums) {
        bool flag = true;
        for(auto i:nums){
            if(i != 0) flag = false;
        }
        if(flag == true) return "0";
        std::sort(nums.begin(),nums.end(),cmp);
        string tmp;
        for(auto i : nums){
            if(tmp.size()==0 && i == 0){
                continue;
            }
            tmp += to_string(i);
        }
        // if(tmp[0] == '0' && tmp.size() > 1) return "0";
        return tmp;
    }
};
// @lc code=end

