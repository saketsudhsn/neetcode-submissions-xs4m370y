class Solution {
public:
    bool isValid(string s) 
    {
        char charStack[s.size()];
        int stackLastIndex = 0;
        charStack[stackLastIndex] = s[0];
        
        int i = 1;
        while(i < s.size())
        {
            if(s[i] == ')')
            {
                if(charStack[stackLastIndex] == '(')
                {
                    std::cout << "Popping\n";
                    stackLastIndex--;
                }
                else
                    return false;
            }
            else if(s[i] == '}')
            {
                if(charStack[stackLastIndex] == '{')
                {
                    std::cout << "Popping\n";
                    stackLastIndex--;
                }
                else
                    return false;
            }
            else if(s[i] == ']')
            {
                if(charStack[stackLastIndex] == '[')
                {
                    std::cout << "Popping\n";
                    stackLastIndex--;
                }
                else
                {
                    std::cout << "Returning false";
                    return false;
                }
            }
            else
                charStack[++stackLastIndex] = s[i];

            i++;
        }

        if(stackLastIndex == -1)
        {
            std::cout << "Returning true";
            return true;
        } 
        else
            return false;
    }
};
