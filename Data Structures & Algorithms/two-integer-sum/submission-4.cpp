class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::vector<int> result;

        std::vector<std::pair<int, int>> numsCopy;
        numsCopy.reserve(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            numsCopy.emplace_back(nums[i], i);
        }

        std::sort(numsCopy.begin(), numsCopy.end());

        int idxPtr1 = 0;
        int idxPtr2 = nums.size() - 1;
        while(idxPtr1 < idxPtr2)
        {
            if(numsCopy[idxPtr1].first + numsCopy[idxPtr2].first == target)
            {
                int& idx1 = numsCopy[idxPtr1].second;
                int& idx2 = numsCopy[idxPtr2].second;
                if(idx1 < idx2)
                    return {idx1, idx2};
                else
                    return {idx2, idx1};

            }
            else if(numsCopy[idxPtr1].first + numsCopy[idxPtr2].first > target)
                idxPtr2--;
            else
                idxPtr1++;
        }

        return {};


        // std::unordered_map<int, int> uMap;
        // for(int i = 0; i<nums.size(); i++)
        // {
        //     int diff = target - nums[i];
        //     if(uMap.find(diff) != uMap.end())
        //     {
        //         return {uMap[diff], i};
        //     }

        //     uMap[nums[i]] = i;
        // }

        // return {};
    }
};
