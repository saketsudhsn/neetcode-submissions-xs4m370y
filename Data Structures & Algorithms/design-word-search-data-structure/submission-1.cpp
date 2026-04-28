class WordDictionary 
{
    struct Node
    {
        std::unordered_map<char, Node*> children;
        bool endOfWord;
    };

    Node* root;

public:
    WordDictionary() : root(new Node())
    {
    }
    
    void addWord(string word) 
    {
        Node* currNode = root;
        for(char c : word)
        {
            if(currNode->children.find(c) == currNode->children.end())
                currNode->children[c] = new Node();

            currNode = currNode->children[c];
        }
        currNode->endOfWord = true;
    }
    
    bool findWord(Node* root, std::string& word, int currIndex)
    {
        if(root->children.empty() || currIndex >= word.size())
            return false;

        // If the child is found
        if(root->children.find(word[currIndex]) != root->children.end())
        {
            std::cout << "currIndex: " << currIndex << ", word size: " << word.size() << "\n";
            std::cout << "Found the child node: " << word[currIndex] << "\n";
            //Reached the end of the word and checking if this word is a part of the trie.
            if((currIndex == word.size() - 1) && root->children[word[currIndex]]->endOfWord)
            {
                std::cout << "Returning true.\n";
                return true;
            }

            return findWord(root->children[word[currIndex]], word, currIndex + 1);
        }
        else
        {
            if(word[currIndex] == '.')
            {
                if(currIndex == word.size() - 1)
                {
                    for(auto child : root->children)
                    {
                        if(child.second->endOfWord)
                            return true;
                    }
                }

                for(auto childNode : root->children)
                {
                    if(findWord(childNode.second, word, currIndex + 1))
                        return true;
                }
            }
        }
        
        return false;
    }

    bool search(string word) 
    {
        return findWord(root, word, 0);
    }
};
