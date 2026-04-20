class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int minBananas = 1;
        int maxBananas = 0;
        for(auto pile : piles)
        {
            if(pile > maxBananas)
                maxBananas = pile;
        }

        int res = maxBananas;
        while(minBananas <= maxBananas)
        {
            int currBananasCount = minBananas + (maxBananas - minBananas)/2;
            
            long long totalTime = 0;
            for(auto p : piles)
            {
                totalTime += ceil(static_cast<double>(p) / currBananasCount);
            }

            if (totalTime <= h) {
                res = currBananasCount;
                maxBananas = currBananasCount - 1;
            } else {
                minBananas = currBananasCount + 1;
            }
        }

        return res;
    }
};
