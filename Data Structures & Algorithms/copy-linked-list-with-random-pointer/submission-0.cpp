/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        std::unordered_map<Node*, Node*> uMap;

        Node* curr = head;
        while(curr)
        {
            Node* newNode = new Node(curr->val);
            uMap[curr] = newNode;
            curr = curr->next;
        }

        curr = head;
        while(curr)
        {
            uMap[curr]->next = curr->next ? uMap[curr->next] : nullptr;
            uMap[curr]->random = curr->random ? uMap[curr->random] : nullptr;
            
            curr = curr->next;
        }

        return uMap[head];
    }
};
