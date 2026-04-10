class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> result(nums.size(), 1);
        int currentProd = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            result[i] = currentProd * nums[i-1];
            currentProd = result[i];
        }

        currentProd = 1;
        for(int i = nums.size() - 1;  i >= 0; i--)
        {
            result[i] = result[i] * currentProd;
            currentProd = nums[i] * currentProd;
        }

        return result;
    }
};
