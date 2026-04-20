class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        auto cmp = [](int a, int b)
        {
            return a > b;
        };

        std::priority_queue<int, std::vector<int>, decltype(cmp)> pQueue(cmp);
        for(auto num : nums)
        {
            pQueue.push(num);
            if(pQueue.size() > k)
                pQueue.pop();
        }
        
        return pQueue.top();        
    }
};
