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
    // ListNode* reverseBetween(ListNode* head, int m, int n) {
    //     if(!head || !head->next || m==n) return head;
    //     ListNode* dummy = new ListNode(0);
    //     dummy->next = head;
    //     ListNode * pre = dummy;
    //     int count = 0;
    //     for( int i = 0 ; i < m-1 ; i++) pre = pre->next;
    //     ListNode * cur = pre->next;
    //     for( int i = m ; i < n ; i++ ){
    //         ListNode * tmp = cur->next;
    //         cur->next = tmp->next;
    //         tmp->next = pre->next;
    //         pre->next = tmp;
    //     }
    //     return dummy->next;
    // }

    //02 递归解法
    ListNode* reverseBetween(ListNode* head, int m , int n ){
        if(m == 1){
            return reverseN(head,n);
        }
        head->next = reverseBetween(head->next , m -1 ,n -1);
        return head;
    }
    ListNode* backnode = nullptr;
    ListNode * reverseN(ListNode* head , int n){
        if(!head) return nullptr;//base case
        if(!head->next || n == 1){
            backnode = head->next;
            return head;//递归终止条件
        }
        ListNode* last = reverseN(head->next , n-1);//递归
        head->next->next = head;//将head指向的东西指向head
        head->next = backnode;//将Head下一个指向null
        return last; 
    }
};
// @lc code=end

