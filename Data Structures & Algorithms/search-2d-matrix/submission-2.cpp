class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        for(auto vec : matrix)
        {
            if(target <= vec[vec.size()-1])
            {
                int i = 0;
                int j = vec.size()-1;

                while(i <= j)
                {
                    int m = i + ((j-i)/2);
                    if(target == vec[m])
                    {
                        return true;
                    }

                    if(target < vec[m])
                        j = m - 1;
                    else
                        i = m + 1;
                }
            }
        }

        return false;
    }
};
