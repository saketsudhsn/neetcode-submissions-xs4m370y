class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> frequencyMap;
        for(auto num : nums)
        {
            frequencyMap[num]++;
        }

        // nums.size() + 1 is required.
        // Example: str = "aaaa";
        // frequency = 4
        // index at which this char will store is 4.
        // so the size of the frequencyGrp needs to be 5 to add the 4th index, 0,1,2,3,4
        std::vector<std::vector<int>> frequencyGrp(nums.size()+1);
        for(auto elem : frequencyMap)
        {
            frequencyGrp[elem.second].push_back(elem.first);
        }

        int arrSize = k;
        std::vector<int> result;
        for(int i = frequencyGrp.size() - 1; i > 0 && result.size() < k; i--)
        {
            for(int elem : frequencyGrp[i])
            {
                result.push_back(elem);
                if(result.size() == k)
                    break;
            }
        }

        return result;
    }
};
