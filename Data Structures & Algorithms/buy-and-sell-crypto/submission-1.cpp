class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxP{};
        int minBuy = prices[0];

        for(auto sell : prices)
        {
            maxP = max(maxP, (sell - minBuy));
            minBuy = min(minBuy, sell);
        }

        return maxP;
    }
};
