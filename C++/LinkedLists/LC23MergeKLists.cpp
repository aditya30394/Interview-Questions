/*
23. Merge k Sorted Lists
Hard

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        {
            return nullptr;
        }
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        
        for(auto l:lists)
        {
            if(l)
            {
                q.push(l);    
            }
            
        }
        
        ListNode* resultHead = new ListNode(0);
        ListNode* tail = resultHead;
        
        while(!q.empty())
        {
            tail->next = q.top();q.pop();
            tail=tail->next;
            ListNode* temp = tail->next;
            if(temp)
            {
                q.push(temp);
            }
        }
        
        return resultHead->next;
                                    
    }
};