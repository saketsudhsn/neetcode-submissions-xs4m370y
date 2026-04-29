/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    std::unordered_map<Node*, Node*> clonedNodes;

public:
    Node* copyNode(Node* sourceNode)
    {
        if(sourceNode == nullptr)
            return sourceNode;
            
        if(clonedNodes.find(sourceNode) != clonedNodes.end())
            return clonedNodes[sourceNode];
        
        Node* newNode = new Node(sourceNode->val);
        clonedNodes[sourceNode] = newNode;
        for(auto neighbor : sourceNode->neighbors)
        {
            newNode->neighbors.push_back(copyNode(neighbor));
        }

        return newNode;
    }

    Node* cloneGraph(Node* node) 
    {
        return copyNode(node);
    }
};
