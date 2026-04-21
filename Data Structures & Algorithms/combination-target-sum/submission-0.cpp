class Solution {
public:
    void findCombinations(int target, int currIndex, std::vector<int>& nums, int currSum, std::vector<int>& tempList, std::vector<std::vector<int>>& result)
    {

        if (currSum > target) {
            return;
        }
        if(currSum == target)
            {
               result.push_back(tempList);
               return;
            }

        for (int i = currIndex; i < nums.size(); i++)
        {
            tempList.push_back(nums[i]);
            currSum += nums[i];
            findCombinations(target, i, nums, currSum, tempList, result);
            tempList.pop_back();
            currSum -= nums[i];

        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        std::vector<std::vector<int>> result;
        std::vector<int> tempList;
        
        findCombinations(target, 0, nums, 0, tempList, result);
        return result;
    }
};
