class Solution {
public:

    void findSubsets(std::vector<int>& nums, int currIndex, std::vector<int>& tempList, std::vector<std::vector<int>>& result)
    {
        if(currIndex >= nums.size())
            return;
        
        for(int i = currIndex; i < nums.size(); i++)
        {
            tempList.push_back(nums[i]);
            result.push_back(tempList);
            findSubsets(nums, i+1, tempList, result);
            tempList.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        std::vector<std::vector<int>> result;
        std::vector<int> tempList;
        result.push_back({});
        findSubsets(nums, 0, tempList,result);
        return result;
    }
};