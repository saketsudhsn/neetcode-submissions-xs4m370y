class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int minEatingRate = 1;
        int maxEatingRate = 0;
        for(auto pile : piles)
        {
            if(pile > maxEatingRate)
                maxEatingRate = pile;
        }

        int res = maxEatingRate;
        while(minEatingRate <= maxEatingRate)
        {
            int midEatingRate = minEatingRate + (maxEatingRate - minEatingRate)/2;
            
            long long totalHrs = 0;
            for(auto pile : piles)
            {
                // ceil(3/2) = ceil(1.5) = 2;
                totalHrs += ceil(static_cast<double>(pile) / midEatingRate);
            }

            if (totalHrs <= h) 
            {
                // Total number of hours taken to consume all the bananas is less than or equal to the time limit.
                // Store the current rate as a valid answer for the current iteration
                // and look for an eating rate that is even lower in the next iteration.
                res = midEatingRate;
                maxEatingRate = midEatingRate - 1;
            } else 
            {
                // The hours taken to consume all the bananas at current rate is exceeding the max hours allowed.
                // So, the minimum eating rate has to be greater than the current mid.
                minEatingRate = midEatingRate + 1;
            }
        }

        return res;
    }
};
