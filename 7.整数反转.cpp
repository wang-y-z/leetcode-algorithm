/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
// class Solution {
// public:
//     int reverse(int x) {
//         int ans = 0;
//         while(x != 0){
//             int pop = x % 10;
//             if(ans>2147483647/10 || (ans==2147483647 /10 && pop >7))
//                 return 0;
//             if(ans<-2147483648 /10 || (ans==-2147483648 /10 && pop <-8))
//                 return 0;
//             ans = ans *10 + pop;
//             x = x/10;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int reverse(int x) {
//         if(x/10 == 0) return x; //平凡情况：若x∈[-9,9]，则直接返回其本身
//         int y = 0;
//         while(x) {
//             if(y > INT_MAX/10 || y < INT_MIN/10) //溢出
//                 return 0;
//             y *= 10;
//             y += x%10; //取出x的个位，存入y中对称的位置
//             x /= 10;   //去掉x的个位
//         }
//         return y;
//     }
// };

class Solution {
public:
    int reverse(int x) {
        long temp = 0, sum = 0;
        while (x != 0) {
            temp = x % 10;
            sum = sum * 10 + temp;
            x = x / 10;
        }
        if (sum >= INT_MAX || sum <= INT_MIN)
            sum = 0;
        return sum;
    }
};
// @lc code=end

