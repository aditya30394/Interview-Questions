/*
83. Remove Duplicates from Sorted List
Easy

Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/

//iterative

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        ListNode* prev=head;
        ListNode* current=head->next;
        
        while(current!=nullptr)
        {
            if(prev->val==current->val)
            {
                ListNode* temp = current;
                current = current->next;
                prev->next = current;
                delete temp;
            }
            else
            {
                prev=current;
                current=current->next;
            }
        }
        
        return head;
        
    }
};

//recursive

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        
        head->next = deleteDuplicates(head->next);
        
        return head->val==head->next->val?head->next:head;
    }
};
