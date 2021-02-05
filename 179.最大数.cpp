/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    //01 自己想的，不断debug发现a+b和b+a定义大小就可以；
    
    // 注：a和b也可以不用传引用（即 &）
    // 注：此处要用static，因为std::sort是属于全局的，无法调用非静态成员函数，而静态成员函数或全局函数是不依赖于具体对象，可以独立访问。
    // 也可以把comparison这个函数放在Solution这个class的外面，但是记住一定要放在整个class的上面而不能是下面。
    // 不然代码里调用sort函数时会找不到comparison，而导致报错。
    static bool cmp( int a , int b ){
        if(a == b) return true;
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i] < s2[i]){
                return false;
            }else if(s1[i]>s2[i]){
                return true;
            }
        }
        return true; 
    }
    static bool cmp_string(  int a , int b ){
        string s1 = to_string(a);
        string s2 = to_string(b);
        return s1+s2>s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        bool flag = true;
        for(auto i:nums){
            if(i != 0) flag = false;
        }
        if(flag == true) return "0";
        std::sort(nums.begin(),nums.end(),cmp_string);
        
        // std::sort(nums.begin(),nums.end(),cmp);
        string tmp;
        for(auto i : nums){
            if(tmp.size()==0 && i == 0){
                continue;
            }
            tmp += to_string(i);
        }
        return tmp;
    }
    //02 大佬解法: 跟大佬想的一样，开心；

};
// @lc code=end