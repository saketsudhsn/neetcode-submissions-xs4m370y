#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size())
            return false;

        std::unordered_map<char, int> sCharMap;
        for(auto ch : s)
        {
            sCharMap[ch]++;
        }

        std::unordered_map<char, int> tCharMap;
        for(auto ch : t)
        {
            tCharMap[ch]++;
        }

        if(sCharMap.size() != tCharMap.size())
            return false;

        for(auto mapElem : sCharMap)
        {
            if(!tCharMap.contains(mapElem.first))
            {
                return false;
            }
            else
            {
                if(tCharMap[mapElem.first] != sCharMap[mapElem.first])
                {
                    return false;
                }
            }
        }

        return true;
    }
};
