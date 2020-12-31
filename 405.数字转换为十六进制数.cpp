/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        // string res;
        stringstream ioss; //定义字bai符串流du
        string s_temp; //存放转化后字符
        ioss << std::hex << num; //以十六制zhi形式输出
        ioss >> s_temp;
        cout<< s_temp <<endl;
        return s_temp;
    }
};
// @lc code=end

