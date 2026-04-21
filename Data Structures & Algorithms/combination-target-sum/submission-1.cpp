class Solution {
public:

    void getCombinations(int target, int currIndex, std::vector<int>& nums, int currSum, std::vector<int>& tempList, std::vector<std::vector<int>>& result)
    {
        if(currSum > target)
            return;
        if(currSum == target)
        {
            result.push_back(tempList);
            return;
        }

        for(int i = currIndex; i < nums.size(); i++)
        {
            currSum += nums[i];
            tempList.push_back(nums[i]);
            getCombinations(target, i, nums, currSum, tempList, result);
            currSum -= nums[i];
            tempList.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        std::vector<std::vector<int>> result;
        std::vector<int> tempList;
        getCombinations(target, 0, nums, 0, tempList, result);
        return result;        
    }
};
