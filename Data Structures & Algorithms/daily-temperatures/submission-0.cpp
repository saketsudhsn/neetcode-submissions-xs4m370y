class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<std::pair<int, int>> tempStack;

        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!tempStack.empty() && tempStack.top().first < temperatures[i])
            {
                std::pair<int, int> tempPair = tempStack.top();
                tempStack.pop();
                result[tempPair.second] = i - tempPair.second;
            }

            tempStack.push({temperatures[i], i});
        }

        return result;
    }
};
