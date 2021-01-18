/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        //01 哈希表 简单
        // unordered_set<ListNode *> t;
        // while( head ){
        //     if(t.count(head)) return head;
        //     t.insert(head);
        //     head = head->next;
        // }
        // return NULL;

        //02 双指针 数学证明有环+一定能在第一圈相遇 ===> 证明起点位置；快慢指针变成等速指针
        if(  head == NULL || head->next == NULL  ){return NULL;}
        ListNode * slow = head;
        ListNode * fast = head;
        while(slow && fast){
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                // ListNode * tmp = slow;
                fast = head;
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};
// @lc code=end

