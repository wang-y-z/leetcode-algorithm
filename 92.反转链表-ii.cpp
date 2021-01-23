/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || m==n) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode * pre = dummy;
        int count = 0;
        for( int i = 0 ; i < m-1 ; i++) pre = pre->next;
        ListNode * cur = pre->next;
        for( int i = m ; i < n ; i++ ){
            ListNode * tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return dummy->next;
    }
};
// @lc code=end

