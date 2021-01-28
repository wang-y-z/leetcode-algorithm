/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    stack<int> stin;
    stack<int> stout;
    
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stin.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stout.empty()){
            while(!stin.empty()){
                stout.push(stin.top());
                stin.pop();
            }
        }
        int res = stout.top();
        stout.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        int res = this->pop();
        stout.push(res);
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stin.empty() && stout.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

