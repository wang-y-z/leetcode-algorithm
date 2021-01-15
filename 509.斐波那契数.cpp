/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
// class Solution {
// public:
//     vector<int> stack;
//     int fib(int n) {
//         stack.push_back(n);
//         return fib(n-1)+stack.back();
//     }
// };

//递归+备忘录——剪枝
class Solution{
public:
    // int fib( int n){
    //     if(n < 1 ) return 0;
    //     vector<int> memo(n+1,0);
    //     return Memo(memo , n);
    // }
    // int Memo(vector<int> & memo , int n ){
    //     if(n==1||n==2) return 1;
    //     if(memo[n] != 0) return memo[n];
    //     memo[n] = Memo(memo,n-1)+Memo(memo,n-2);
    //     return memo[n];
    // }

    //动规——其实不算，因为没有转移状态
    int fib( int n){
        if(n < 1 ) return 0;
        if(n==1||n==2) return 1;
        vector<int> dp(n+1,0);
        dp[1] = dp[2] = 1;
        for(int i = 3 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    //进一步将有限的三个状态用三个Int来存储——状态压缩；减少空间消耗；
    
};
// @lc code=end

