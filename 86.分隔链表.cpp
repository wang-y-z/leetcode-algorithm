/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* s = new ListNode(-1) , *h1 = s;
        ListNode* l = new ListNode(-1) , *h2 = l;
        while(head){
            if(head->val < x){
                h1->next = head;
                h1 = h1->next;
            }else{
                h2->next = head;
                h2 = h2->next;
            }
            head = head->next;
        }
        h1->next = NULL;
        h2->next = NULL;
        h1->next = l->next;

        return s->next;
    }
};
// @lc code=end

