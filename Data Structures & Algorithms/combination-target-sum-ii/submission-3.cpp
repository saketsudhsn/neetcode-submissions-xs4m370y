class Solution {
public:
    void getCombinations(int currIndex, std::vector<int>& candidates, int target, int currSum, std::vector<int>& tempList, std::vector<std::vector<int>>& result)
    {
        if(currSum == target)
        {
            result.push_back(tempList);
            return;
        }
        if(currSum > target)
        {
            return;
        }

        for(int i = currIndex; i < candidates.size(); i++)
        {
            // skip duplicates at the same recursion level
            if(i > currIndex && candidates[i] == candidates[i - 1])
            {
                 continue;
            }

            currSum += candidates[i];
            tempList.push_back(candidates[i]);
            getCombinations(i+1, candidates, target, currSum, tempList, result);
            tempList.pop_back();
            currSum -= candidates[i];
        }        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> tempList;
        std::vector<std::vector<int>> result;
        getCombinations(0, candidates, target, 0, tempList, result);
        return result;
    }
};
