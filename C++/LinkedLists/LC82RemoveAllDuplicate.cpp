/*
82. Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Extremely ugly solution
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        
        ListNode* temp=new ListNode(INT_MAX), *current=head;
        int current_match=INT_MAX;
        ListNode* prev=temp,*prev2=temp;
        while(current!=nullptr)
        {
            if(current->val==current_match)
            {
                current = current->next;
                prev2->next=nullptr;
                prev = prev2;
                
            }
            else
            {
                current_match=current->val;
                prev->next=current;
                prev2=prev;
                current=current->next;
                prev=prev->next;
            }
        }
        return temp==prev?nullptr:temp->next;
    }
};


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        
        ListNode* temp=new ListNode(INT_MAX);
        temp->next=head;    
        ListNode* prev=temp;
        ListNode* current=head;
            
        while(current!=nullptr)
        {
            while(current->next!=nullptr && current->val==current->next->val)
            {
                current=current->next;//skip all the duplicates
            }
            if(prev->next!=current)
            {
                prev->next=current->next;
            }
            else
            {
                prev = prev->next;
            }
            current=current->next;
        }
        return temp->next;
    }
};

