/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        unsigned long  size = heights.size();
        if(size == 1) return heights[0];
        int res = 0;
        stack<int> stk;
        //单调栈只遍历一次，遍历的过程中维护单调递增栈，若出现栈顶元素比当前元素还大，说明
        //可以开始计算面积了，因为栈顶左边比他小，右边也比他小，记录下这个i就能算出左右加起来的
        //宽度；
        for(int i = 0 ; i<size ; i++){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                int length = heights[stk.top()];
                stk.pop();
                int weight = i;
                if(!stk.empty()){
                    weight = i - stk.top() - 1;
                }
                res = max(res , length*weight);
            }
            stk.push(i);
        }
        // cout<< res <<endl; 
        //遍历完第一遍之后，栈内若还有元素，说明这些index对应的柱子还没有被计算，再遍历一下栈就行
        //此时需要注意这些栈向右延伸可以到最右边；他们基本就是最小的柱子了；
        //注意边界条件：如果pop完是空栈，说明pop掉的是最小的柱子，那他的长度必是size
        while(!stk.empty()){
            int length = heights[stk.top()];
            stk.pop();
            int weight = size;
            if(!stk.empty()){
                weight = size - stk.top() - 1;
            }
            res = max(res,length * weight);
        }
        return res;
    }
};
// @lc code=end

