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
            if(stackLastIndex == -1 && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
                return false;

            if(s[i] == ')')
            {
                if(charStack[stackLastIndex] == '(')
                    stackLastIndex--;
                else
                    return false;
            }
            else if(s[i] == '}')
            {
                if(charStack[stackLastIndex] == '{')
                    stackLastIndex--;
                else
                    return false;
            }
            else if(s[i] == ']')
            {
                if(charStack[stackLastIndex] == '[')
                    stackLastIndex--;
                else
                    return false;
            }
            else
                charStack[++stackLastIndex] = s[i];

            i++;
        }

        if(stackLastIndex == -1)
            return true;
        else
            return false;   
    }
};
