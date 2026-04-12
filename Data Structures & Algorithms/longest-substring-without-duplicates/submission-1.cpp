class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        std::vector<int> last(256, -1);
        int start = 0;
        int maxLen = 0;

        for(int i = 0; i < s.size(); i++)
        {
            unsigned char c = s[i];

            // If the character was seen before and its last occurrence lies within the current window
            // (i.e., last[c] >= start), then we have found a repeating character.
            // Move the start of the window to one position after the previous occurrence
            // to maintain a substring with all unique characters.
            if(last[c] >= start)
                start = last[c]+1;

            last[c] = i;
            int currLen = i - start + 1;
            maxLen = max(maxLen, currLen);            
        }

        return maxLen;
    }
};
