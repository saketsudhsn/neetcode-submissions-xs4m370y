class PrefixTree 
{
private:
    struct Node
    {
        std::unordered_map<char, Node*> children;
        bool endOfWord{};
    };

    Node* root;

public:

    PrefixTree() 
    {
        root = new Node();    
    }
    
    void insert(string word) 
    {
        Node* currNode = root;
        for(char c : word)
        {
            if(currNode->children.find(c) == currNode->children.end())
            {
                currNode->children[c] = new Node();
            }
            
            currNode = currNode->children[c];
        }
        
        currNode->endOfWord = true;
    }
    
    bool search(string word) 
    {
        Node* currNode = root;
        for(char c : word)
        {
            if(currNode->children.find(c) == currNode->children.end())
            {
                return false;
            }
            
            currNode = currNode->children[c];
        }
        
        return currNode->endOfWord;
    }
    
    bool startsWith(string prefix) 
    {
        Node* currNode = root;
        for(char c : prefix)
        {
            if(currNode->children.find(c) == currNode->children.end())
                return false;
            
            currNode = currNode->children[c];
        }
        
        return true;        
    }
};
