class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        std::unordered_set<int> numsSet;
        for(int i = 0; i < nums.size(); i++)
        {
            numsSet.insert(nums[i]);
        }

        std::vector<std::vector<int>> validSequences;
        for(auto elem : numsSet)
        {
            if(!numsSet.contains(elem-1))
                validSequences.push_back({elem});
            
        }

        for(auto& sequence : validSequences)
        {
            int i = 0;
            while(true)
            {
                auto it = numsSet.find(sequence[i]+1);
                if (it != numsSet.end())
                {
                    sequence.push_back(*it);
                    i++;
                }
                else
                {
                    break;
                }

            }
        }

        int result = 0;
        for(auto& sequence : validSequences)
        {
            if(sequence.size() > result)
            {
                result = sequence.size();
            }
        }

        return result;
    }
};
