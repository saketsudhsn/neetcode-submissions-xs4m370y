class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        std::vector<int> freqVec(nums.size()+1);
        for(int i = 0; i < nums.size(); i++)
        {
            if(++freqVec[nums[i]] > 1)
                return nums[i];
        }
    }
};
