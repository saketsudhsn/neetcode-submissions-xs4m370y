class KthLargest {
public:
    int k;
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    KthLargest(int k, vector<int>& nums) : k(k)
    {
        for(auto elem : nums)
        {            
            minHeap.push(elem);
            if(minHeap.size() > k)
                minHeap.pop();
        }        
    }

    int add(int val) 
    {
        std::cout << minHeap.size() << ", k: " << k << "\n";

        minHeap.push(val);

        if(minHeap.size() > k)
                minHeap.pop();
                
        return minHeap.top();        
    }
};
