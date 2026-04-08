#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size())
            return false;

        std::vector<int> count(26);
        for(int i = 0; i < s.size(); i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(auto num : count)
        {
            if(num != 0)
            {
                return false;
            }
        }

        return true;
    }
};
