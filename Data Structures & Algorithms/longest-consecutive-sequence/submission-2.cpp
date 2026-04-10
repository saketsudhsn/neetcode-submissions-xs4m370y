class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        std::unordered_set<int> numsSet(nums.begin(), nums.end());

        std::vector<int> validSequences;
        for(auto elem : numsSet)
        {
            if(!numsSet.contains(elem-1))
                validSequences.push_back(elem);
        }


        int result = 0;
        for(auto& sequence : validSequences)
        {
            int currSequenceLength = 0;
            int currNum = sequence;
            while(true)
            {
                auto it = numsSet.find(currNum++);
                if (it != numsSet.end())
                {
                    currSequenceLength++;
                }
                else
                {
                    break;
                }
            }
            if(result < currSequenceLength)
                result = currSequenceLength;
        }

        return result;
    }
};
