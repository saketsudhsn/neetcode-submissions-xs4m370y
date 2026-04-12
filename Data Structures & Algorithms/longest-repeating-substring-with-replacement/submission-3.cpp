class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        std::unordered_map<char, int> windowCharCount;

        int maxFreq = 0;
        int start = 0;
        int result = 0;
        for(int i = 0; i < s.size(); i++)
        {
            windowCharCount[s[i]]++;
            maxFreq = max(maxFreq, windowCharCount[s[i]]);
            
            int currWindowSize = i - start + 1;
            if(currWindowSize - maxFreq > k)
            {
                windowCharCount[s[start]]--;
                start++;
            }

            result = max(result, i - start + 1);
        }

        return result;

    }
};
