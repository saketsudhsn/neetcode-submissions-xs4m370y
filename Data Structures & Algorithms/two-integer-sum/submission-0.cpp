#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::unordered_map<int, int> uMap;
        for(int i = 0; i<nums.size(); i++)
        {
            int diff = target - nums[i];
            if(uMap.find(diff) != uMap.end())
            {
                return {uMap[diff], i};
            }

            uMap[nums[i]] = i;
        }

        return {};
    }
};
