class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        // Start with an empty subset already a part of the subsets
        vector<vector<int>> res = {{}};

        // Iterate through all the elements of the input vector
        for (int num : nums) {
            // Storing the size of the result vector so that we can 
            int size = res.size();
            for (int i = 0; i < size; i++) 
            {
                //Creating a vector equivalent to the current iterating subset.
                vector<int> subset = res[i];
                subset.push_back(num);
                res.push_back(subset);
            }
        }

        return res;
    }
};