/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> count(10);
        bool used[10];
        memset(used,false,sizeof(used));
        string res = "";

        for(auto c : num){
            count[atoi(c)] ++;
        }
        for(auto c : s){
            count[atoi(c)]--;
            if(used[c-'a']) continue;
            while( res.length()>0&& c < res[res.length()-1] && count[res[res.length()-1] - 'a']>0){
                used[res[res.length()-1] - 'a'] = false;
                res.erase(res.length()-1);
            }
            res += c;
            used[c-'a']=true;
        }
        return res;
    }
    }
};
// @lc code=end

