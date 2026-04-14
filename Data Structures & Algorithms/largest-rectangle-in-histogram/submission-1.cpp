class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int maxArea{};
        std::stack<int> indicesStack;

        for(int i = 0; i <= heights.size(); i++)
        {
            while(!indicesStack.empty() && (i == heights.size() || heights[indicesStack.top()] >= heights[i]))
            {
                int rectHeight = heights[indicesStack.top()];
                std::cout << "pop - heights[" << indicesStack.top() << "] : " << rectHeight << "\n";

                indicesStack.pop();
                int rectWidth{};
                if(indicesStack.empty())
                {
                    rectWidth = i;
                }
                else
                {
                    rectWidth = i - indicesStack.top() - 1;
                }
                
                maxArea = max(maxArea, rectHeight * rectWidth);
            }
            
            std::cout << "push - heights[" << i << "] : " << heights[i] << "\n";
            indicesStack.push(i);
            
        }

        return maxArea;        
    }
};
