class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        std::unordered_map<std::string, std::vector<string>> anagramsStringsGrp;
        for(int i = 0; i < strs.size(); i++)
        {
            std::vector<int> chars(26);
            std::string& currString = strs[i];
            for(int j = 0; j < currString.size(); j++)
            {
                chars[currString[j] - 'a']++;
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
