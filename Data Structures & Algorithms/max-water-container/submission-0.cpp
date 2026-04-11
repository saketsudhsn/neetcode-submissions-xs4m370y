class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int result{};
        int i = 0;
        int j = heights.size()-1;

        while(i<j)
        {
            int area = min(heights[i], heights[j]) * (j-i);
            if(result < area)
                result = area;

            if(heights[i] <= heights[j])
                i++;
            else
                j--;
        }
        
        return result;
    }
};
