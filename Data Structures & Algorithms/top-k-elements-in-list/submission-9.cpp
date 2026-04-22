class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> uMap;
        for(auto num : nums)
        {
            uMap[num]++;
        }

        auto cmp = [](std::pair<int, int> a, std::pair<int, int> b)
        {
            return a.second < b.second;
        };

        int count = k;
        std::vector<int> result;
        result.reserve(count);
        
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pQueue(cmp);
        auto itr = uMap.begin();
        while(itr != uMap.end())
        {
            pQueue.push({itr->first, itr->second});
            itr++;
        }

        while(count && !pQueue.empty())
        {
            result.push_back(pQueue.top().first);
            pQueue.pop();
            count--;  
        }

        return result;
    }
};
