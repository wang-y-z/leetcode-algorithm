/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

// @lc code=start
// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         if(num.size() <= k) return "0";
//         string res = "";

//         for(auto c : num){
//             while( res.length()>0&& c < res[res.length()-1] && k > 0){
//                 res.erase(res.length()-1);
//                 k--;
//             }
//             res += c;
//         }
//         // cout<< "k: " << k <<endl;
//         int count = 0;
//         for(auto i = res.begin() ; i != res.end()  ; ++i){
//             if(*i == '0') {
//                 count++;
//             }else{
//                 // res.erase(i);
//                 break;
//             }
//         }
//         // int len = res.length();
//         // res.substr(count,len-count);
//         res.erase(0,count);
//         while( k != 0){
//             res.pop_back();
//             k--;
//         }
//         if(res.length()>0){
//             return res;
//         }else{
//             return "0";
//         }
//         // cout<< count <<endl;
//         // return res;
//     }
// };
class Solution {
public:
    string removeKdigits(string num, int k) {
       if (num.size() == 0) return "0";
       deque<char> Q;
       for (char C: num) {
           while (k > 0 && Q.size() > 0 && C < Q.back()) {
               Q.pop_back(); k--;
           }
           if (C != '0' || Q.size() != 0)
               Q.push_back(C);
       }
       if (Q.size() == 0)   return "0";
       while (k > 0) {
           Q.pop_back();
           k--;
       }
       if (Q.size() == 0)   return "0";
       string ans;
       while (Q.size() != 0) {
           ans.push_back(Q.front());
           Q.pop_front();
       }
       return ans;
    }
};
// @lc code=end

