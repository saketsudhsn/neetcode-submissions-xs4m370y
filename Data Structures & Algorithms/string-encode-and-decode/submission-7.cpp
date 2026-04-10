class Solution {
public:

    string encode(vector<string>& strs) 
    {
        std::string outStr;
        for(auto str : strs)
        {
            outStr += std::to_string(str.size()) + "#" + str;
        }
        std::cout << "outStr: " << outStr << "\n";
        return outStr;
    }

    vector<string> decode(string s) 
    {
        std::vector<std::string> strs;

        int i = 0;
        while(i < s.size())
        {
            int numLength{};
            while(s[i] != '#')
            {
                i++;
                numLength++;
            }

            int size = stoi(s.substr(i-numLength, numLength));
            strs.push_back(s.substr(i+1, size));
            i += size+1;
        }

        return strs;

    }
};
