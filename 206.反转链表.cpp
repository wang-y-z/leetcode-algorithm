/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // ListNode* reverseList(ListNode* head) {
    //     ListNode * pre = NULL;
    //     ListNode * cur = head;
    //     while( cur ){
    //         ListNode * tmp = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = tmp;
    //     }   
    //     return pre;     
    // }
    //02 递归实现
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;//base case
        if(!head->next) return head;//递归终止条件
        ListNode* last = reverseList(head->next);//递归
        head->next->next = head;//将head指向的东西指向head
        head->next = nullptr;//将Head下一个指向null
        return last; 
    }
};
// @lc code=end

