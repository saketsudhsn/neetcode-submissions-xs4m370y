class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        std::unordered_map<std::string, std::vector<string>> anagramsStringsGrp;
        for(const std::string& currString : strs)
        {
            std::vector<int> chars(26);
            for(const char& c : currString)
            {
                chars[c - 'a']++;
            }


            std::string key = std::to_string(chars[0]);
            for(int i = 1; i < 26; i++)
            {
                key += ',' + std::to_string(chars[i]);
            }

            anagramsStringsGrp[key].push_back(currString);
        }

        std::vector<std::vector<std::string>> output;
        for(const auto& pair : anagramsStringsGrp)
        {
            output.push_back(pair.second);
        }
        
        return output;
                
    }
};
