class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int i = 0;
        int j = 0;

        std::vector<int> mergedArray;
        while(i < nums1.size() &&  j < nums2.size())
        {
            if(nums1[i] < nums2[j])
                mergedArray.push_back(nums1[i++]);
            else
                mergedArray.push_back(nums2[j++]);
        }

        while(i < nums1.size()) mergedArray.push_back(nums1[i++]);
        while(j < nums2.size()) mergedArray.push_back(nums2[j++]);

        int m = mergedArray.size()/2;
        if(mergedArray.size()%2 == 0)
        {
            return ((double)(mergedArray[m] + mergedArray[m-1]))/2;
        }
        else
        {
            return mergedArray[m];
        }
                
    }
};
