// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem66.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    //01 丑陋的递归hhh，不知道为什么就用了递归
    // int count = 0;
    // vector<int> plusOne(vector<int>& digits) {
    //     if( digits.back() < 9 ){
    //         digits.back() ++;
    //         for( int i = 0 ; i < count ; i++ ){
    //             digits.push_back(0);
    //         }
    //         return digits;
    //     }else{
    //         digits.back() = 0;
    //         digits.pop_back();
    //         if(digits.size() == 0){
    //             digits = {0};
    //         }
    //         count++;
    //         return plusOne(digits);
    //     }
    // }

    //02  大佬解法   if的位置是精髓
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1 ; i >= 0 ; i--){
            digits[i]++;
            digits[i] = digits[i] % 10;
            if( digits[i] != 0 ) return digits;            
        }
        vector<int> di(digits.size() + 1);//如果之前都没返回说明全是9，说明该New一个ve了
        di[0] = 1;
        return di;
    }

};
// @lc code=end

