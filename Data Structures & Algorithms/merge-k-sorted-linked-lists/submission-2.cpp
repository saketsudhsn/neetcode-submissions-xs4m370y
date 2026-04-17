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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        auto cmp = [](ListNode* node1, ListNode* node2)
        {
            return node1->val > node2->val;
        };

        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pQueue(cmp);
        for(ListNode* head : lists)
        {
            if(head)
                pQueue.push(head);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(!pQueue.empty())
        {
            ListNode* top = pQueue.top();
            pQueue.pop();
            
            tail->next = top;
            tail = tail->next;

            if(top->next)
                pQueue.push(top->next);
        }

        tail->next = nullptr;
        return dummy.next;
    }
};
