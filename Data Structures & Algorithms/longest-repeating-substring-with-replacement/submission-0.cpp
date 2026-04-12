class Solution {
public:
    int characterReplacement(string s, int k) 
    {

        std::unordered_map<char, int> charCount;

        int maxFreq = 0;
        int start = 0;
        int result = 0;
        for(int i = 0; i < s.size(); i++)
        {
            charCount[s[i]]++;
            maxFreq = max(maxFreq, charCount[s[i]]);
            
            if ((i - start + 1) - maxFreq > k)
            {
                charCount[s[start]]--;
                start++;
            }

            result = max(result, i - start + 1);
        }

        return result;

    }
};
