class Solution {
public:
    void getSubsets(int currIndex, std::vector<int>& nums, std::vector<int>& tempList, std::vector<std::vector<int>>& result)
    {
        if(currIndex > nums.size())
        {
            return;
        }

        for(int i = currIndex; i < nums.size(); i++)
        {
            if((i > currIndex) && (nums[i] == nums[i-1]))
                continue;

            tempList.push_back(nums[i]);
            result.push_back(tempList);
            getSubsets(i+1, nums, tempList, result);
            tempList.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        std::vector<int> tempList;
        std::vector<std::vector<int>> result;

        std::sort(nums.begin(), nums.end());
        result.push_back({});
        getSubsets(0, nums, tempList, result);
        return result;
    }
};
