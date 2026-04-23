class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        std::vector<int> result(nums.size(), 1);

        int currProd = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            result[i] = currProd * nums[i-1];
            currProd = result[i];
        }

        currProd = 1;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            result[i] = result[i] * currProd;
            currProd *= nums[i] ;
        }

        return result;
    }
};

// arr      : 1, 2, 4, 6
// cp       : 1, 1, 2, 8
// result   : 1, 2, 16, 8
