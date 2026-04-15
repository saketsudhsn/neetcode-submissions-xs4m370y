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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* prevNode = nullptr;
        ListNode* currNode = nullptr;
        ListNode* head{};

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        while(curr1 && curr2)
        {
            if(curr1->val <= curr2->val)
            {
                currNode = curr1;
                curr1 = curr1->next;
            }
            else
            {
                currNode = curr2;
                curr2 = curr2->next;
            }

            if(prevNode)
            {
                prevNode->next = currNode;
            }
            if(!head)
                head = currNode;
            prevNode = currNode;
        }

        if(curr1)
        {
            if(currNode)
                currNode->next = curr1;
            else
                head = curr1;

        }
        else if(curr2)
        {
            if(currNode)
                currNode->next = curr2;
            else
                head = curr2;
        }

        return head;
    }
};
