class Solution {
public:

    std::string getWindowFreqStr(const std::string& str)
    {
        std::vector<int> windowCharFreq(26, 0);
        for(int i = 0; i < str.size(); i++)
        {
            windowCharFreq[str[i]-'a']++;
        }

        std::string sWindowCharFreq;
        for(int i = 0; i < 26; i++)
        {
            sWindowCharFreq.append(std::to_string(windowCharFreq[i]));
        }
        
        return sWindowCharFreq;
    }

    bool checkInclusion(string s1, string s2) 
    {
        int windowSize = s1.size();
        if(s2.size() < windowSize)
            return false;
        else if(s1 == s2)
            return true;
        
        std::unordered_set<std::string> s1FreqSet;
        s1FreqSet.insert(getWindowFreqStr(s1));

        int startIdx = 0;
        int lastIdx = windowSize - 1;
        while(lastIdx < s2.size())
        {
            if(s1FreqSet.contains(getWindowFreqStr(s2.substr(startIdx, windowSize))))
                return true;
            
            startIdx++;
            lastIdx++;
        }
        
        return false;
    }
};
