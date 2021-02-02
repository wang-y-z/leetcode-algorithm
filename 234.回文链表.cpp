/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //01 数组保存再双指针对比；优化的点有，vector开辟的开销；遍历两次
    // bool isPalindrome(ListNode* head) {
    //     vector<int> res;
    //     while(head){
    //         res.push_back(head->val);
    //         head = head->next;
    //     }
    //     for( int i  = 0 , j = res.size()-1 ; i <j ; i++,j-- ){
    //         if( res[i] != res[j] ) return false;
    //     }
    //     return true;
    // }
    //02 直接从数据结构的角度出发：用栈保存再取top和pop对比是否相等
    //前提：快慢指针，1,2， 这样快走到最后慢指针走到中间；
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* s = head;
        ListNode* f = head;
        stack<int> st;
        int count = 0;
        while( f && f->next ){
            st.push(s->val);
            s = s->next;
            f = f->next->next;
        }
        if(f){
            s = s->next;
        }
        while( s ){
            if(st.top() != s->val) return false;
            s = s->next;
            st.pop();
        }
        return true;
    }
    //03 还有个办法：快慢指针，慢指针到中间之后开始使用反转链表的方法翻转
    //todo
};
// @lc code=end

