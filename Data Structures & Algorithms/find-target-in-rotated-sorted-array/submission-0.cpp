class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0;
        int r = nums.size() - 1;
        int pivot = l;

        while(l <= r)
        {
            if(nums[l] < nums[r])
            {
                if(nums[l] < nums[pivot])
                {
                    pivot = l;
                }

                break;
            }

            int m = l + ((r-l)/2);
            if(nums[m] < nums[pivot])
            {
                pivot = m;
            }

            if(nums[m] < nums[l])
                r = m -1;
            else
                l = m + 1;
        }

        std::cout << "minVal: " << nums[pivot] << ", pivot index: " << pivot << "\n";
        if(target > nums[nums.size() - 1])
        {
            l = 0;
            r = pivot -1;
        }
        else
        {
            l = pivot;
            r = nums.size() - 1;
        }

        std::cout << "l: " << l << ", r: " << r << "\n";

        int res = -1;
        while(l <= r)
        {
            int m = l + ((r-l)/2);
            if(nums[m] == target)
            {
                res = m;
                break;
            }

            if(target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        }

        return res;
    }
};
