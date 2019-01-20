/*
92. Reverse Linked List II
Medium

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if(head==nullptr)
        {
            return head;
        }
        
        int i=1;
        ListNode *curr=head,*before=nullptr;
        for(i=1;i<m;++i)
        {
            before=curr;
            curr=curr->next;
        }
        
        ListNode* prev=nullptr, *next=nullptr, *start=curr;
        
        for(i=m;i<=n;++i)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        if(before)
        {
            before->next=prev;
        }
        else
        {
            head = prev;
        }
        start->next=curr;
        
        return head;
    }
};
