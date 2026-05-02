class Solution {
public:
    void printMap(std::unordered_map<int, int>& uMap, vector<int>& nums)
    {
        std::printf("uMap size: %d\n", uMap.size());
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            std::cout << nums[i] << ": " << uMap[nums[i]] << "\n";
        }
        std::cout << "\n";
    }

    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        std::unordered_map<int, int> freqMap;
        for(int i = 0; i < nums.size(); i++)
        {
            freqMap[nums[i]]++;
        }
        //printMap(freqMap, nums);

        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++)
        {
            freqMap[nums[i]]--;
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            for(int j = i + 1; j < nums.size(); j++)
            {
                freqMap[nums[j]]--;
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;

                int target = - (nums[i] + nums[j]);
                if((freqMap.find(target) != freqMap.end()) && (freqMap[target] > 0))
                {
                    result.push_back({nums[i], nums[j], target});
                }
            }

            for(int j = i + 1; j < nums.size(); j++)
            {
                freqMap[nums[j]]++;
            }
            //printMap(freqMap, nums);
        }

        return result;
    }
};
