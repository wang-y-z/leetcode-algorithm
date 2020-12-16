/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * res = new ListNode(-1);
        ListNode * h = res ;
        int sum = 0;
        bool carry = false;
        // cout<< !l1 <<endl;
        // cout<< (l1!=NULL) <<endl;
        while( l1 || l2 ){
            cout<<"test"<<endl;
            sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            if(carry){
                sum++;
            }
            h->next = new ListNode( sum%10 );
            h = h->next;
            carry = sum >= 10 ? true : false;
        }
        if(carry) h->next = new ListNode(1);

        return res->next;
    }
};
// @lc code=end

