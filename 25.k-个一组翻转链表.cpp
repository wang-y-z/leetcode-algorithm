/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    //此题递归很有韵味
    ListNode* reverseab(ListNode* a, ListNode* b){
        ListNode* pre = nullptr;
        ListNode* cur = a;
        ListNode* nxt = b;
        while( cur != b ){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* a = head;
        ListNode* b = head;
        for(int i = 0 ; i< k ; i++){
            if(b == nullptr) return head;
            b = b->next;
        }
        ListNode* newHead = reverseab(a,b);
        a->next = reverseKGroup(b,k);
        return newHead;
    }
};
// @lc code=end

