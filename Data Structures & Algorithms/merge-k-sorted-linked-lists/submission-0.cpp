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
        for(ListNode* linkedList : lists)
        {
            ListNode* curr = linkedList;
            while(curr)
            {
                pQueue.push(curr);
                curr = curr->next;
            }
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(!pQueue.empty())
        {
            curr->next = pQueue.top();
            pQueue.top()->next = nullptr;
            curr = curr->next;
            pQueue.pop();
        }

        return dummy.next;
    }
};
