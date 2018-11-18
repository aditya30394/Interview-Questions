/*
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(INT_MAX);
        ListNode* head = temp;
        int carry =0;
        
        while(l1 || l2 || carry)
        {
            ListNode* newdata = new ListNode(carry);
            newdata->val = newdata->val + (l1?l1->val:0) + (l2?l2->val:0);
            carry = newdata->val/10;
            newdata->val = newdata->val%10;
            temp->next = newdata;
            temp=temp->next;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
                
        }
        temp = head;
        head=head->next;
        delete temp;
        return head;
    }
};