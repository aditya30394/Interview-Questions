/*
143. Reorder List
Medium

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

//cleaner
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
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr)
        {
            return ;
        }
        
        ListNode *slow = head, *fast = head, *end=head;
        
        while(fast && fast->next && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        end=slow->next;
        slow->next=nullptr;
        ListNode*rHead = reverse(end);
        
        ListNode* start=head,*tail;
        while(start && rHead)
        {
            ListNode* temp1 = start->next;
            ListNode* temp2 = rHead->next;
            tail=rHead;
            start->next = rHead;
            rHead->next=temp1;
            start = temp1;
            rHead = temp2;
        }
        
        return;
    }
    
    ListNode* reverse(ListNode* head)
    {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        
        ListNode*prev=nullptr, *curr=head,*temp;
        
        while(curr)
        {
            temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
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
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return ;
        }
        
        ListNode *slow = head, *fast = head, *end=head;
        
        while(fast && fast->next)
        {
            end=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        end->next=nullptr;
        slow=reverse(slow);
        
        ListNode* start=head,*tail;
        while(start && slow)
        {
            ListNode* temp1 = start->next;
            ListNode* temp2 = slow->next;
            tail=slow;
            start->next = slow;
            slow->next=temp1;
            start = temp1;
            slow = temp2;
        }
        if(start==nullptr && slow!=nullptr)
        {
            //odd length list
            tail->next=slow;
        }
        return;
    }
    
    ListNode* reverse(ListNode* head)
    {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        
        ListNode*prev=nullptr, *curr=head,*temp;
        
        while(curr)
        {
            temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};

