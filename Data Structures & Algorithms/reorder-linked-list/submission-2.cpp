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

    void reorderList(ListNode* head)
    {
        if(!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        //Finding the middle of the list and breaking it in two parts
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list1 = head;
        ListNode* list2 = slow->next;
        slow->next = nullptr;

        //Reversing the list2
        ListNode* currNode = list2;
        ListNode* prevNode = nullptr;
        while(currNode)
        {
            ListNode* temp = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = temp;
        }

        list2 = prevNode;

        ListNode* masterPtr = head;
        while(masterPtr && list2)
        {
            ListNode* temp1 = masterPtr->next;
            ListNode* temp2 = list2->next;

            masterPtr->next = list2;
            list2->next = temp1;
            masterPtr = temp1;
            list2 = temp2;
        }
    }
};