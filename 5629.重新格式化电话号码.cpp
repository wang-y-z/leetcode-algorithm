/*
 * @lc app=leetcode.cn id=5629 lang=cpp
 *
 * [5629] 重新格式化电话号码
 */

// @lc code=start
class Solution {
public:
    string reformatNumber(string number) {
        string res;
        int count = 0;
        for(char & i : number){
            if(isalnum(i)){
                res += i;
                count++;
                if(count == 3){
                    count = 0;
                    res += '-';
                }
            }
        }
        int leng = res.length();
        if(leng < 2 ) return res;
        if(leng % 4 == 0){
            res.pop_back();
        }else if(leng % 4 == 1){
            swap(res[leng - 2],res[leng - 3]);
        }
        return res;
    }
};
// @lc code=end

