#include <unordered_set>

class Solution 
{
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        std::unordered_set<int> uniqueNumbers;
        for(auto num : nums)
        {
            if(uniqueNumbers.contains(num))
                return true;

            uniqueNumbers.insert(num);
        }

        return false;
    }
};