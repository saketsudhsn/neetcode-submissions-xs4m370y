class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j)
        {
            int m = i + ((j-i)/2);
            if(target == nums[m])
                return m;

            if(target < nums[m])
                j = m - 1;
            else
                i = m + 1;
        }

        return -1;
    }
};
