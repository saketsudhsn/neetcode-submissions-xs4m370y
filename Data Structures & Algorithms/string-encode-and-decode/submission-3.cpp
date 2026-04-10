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
            std::string sStrSize;
            int numLength{};
            while(s[i] != '#')
            {
                sStrSize += s[i++];
                numLength++;
            }

            int size = stoi(sStrSize);
            std::string str(s.begin()+i+1, s.begin()+i+1+size);
            strs.push_back(str);
            i += size+1;
        }

        return strs;

    }
};
