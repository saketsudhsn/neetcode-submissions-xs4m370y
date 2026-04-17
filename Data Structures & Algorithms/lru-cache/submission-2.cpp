class LRUCache {
public:

    struct ListNode
    {
        int key{};
        int value{};
        ListNode* next{};
        ListNode* prev{};
        ListNode(int key, int val) : key(key), value(val), next(nullptr), prev(nullptr) {}
    };

    void EraseNode(ListNode* node)
    {
        ListNode* prev = node->prev;
        ListNode* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    void InsertNode(ListNode* node)
    {
        ListNode* prev = mru->prev;
        prev->next = node;
        node->prev = prev;
        node->next = mru;
        mru->prev = node;
    }

    ListNode* lru;
    ListNode* mru;
    
    int m_capacity;
    std::unordered_map<int, ListNode*> uMap;

    LRUCache(int capacity) : m_capacity(capacity)
    {
        lru = new ListNode(0, 0);
        mru = new ListNode(0, 0);
        lru->next = mru;
        mru->prev = lru;
    }
    
    int get(int key)
    {
        if(uMap.find(key) == uMap.end())
            return -1;
        
        ListNode* node = uMap[key];
        EraseNode(node);
        InsertNode(node);
        return node->value;
    }
    
    void put(int key, int value) 
    {
        ListNode* node;
        if(uMap.find(key) != uMap.end())
        {
            node = uMap[key];
            node->value = value;
            EraseNode(node);
            InsertNode(node);

            return;
        }

        node = new ListNode(key, value);
        InsertNode(node);
        uMap[key] = node;

        if(uMap.size() > m_capacity)
        {
            ListNode* delNode = uMap[lru->next->key];
            EraseNode(delNode);
            uMap.erase(delNode->key);
            delete delNode;
        }
    }
};
