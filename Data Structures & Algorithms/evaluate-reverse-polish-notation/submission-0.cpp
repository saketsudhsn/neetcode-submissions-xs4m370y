class Solution {
public:

    std::stack<string> strStack;
    enum class OPER
    {
        ADD,
        SUB,
        MUL,
        DIV
    };

    void calculateAndUpdateStack(OPER op)
    {
        int val1 = std::stoi(strStack.top());
        strStack.pop();
        int val2 = std::stoi(strStack.top());
        strStack.pop();

        switch(op)
        {
            case OPER::ADD:
            {
                strStack.push(std::to_string(val1+val2));
                break;
            }
            case OPER::SUB:
            {
                strStack.push(std::to_string(val2-val1));
                break;
            }
            case OPER::MUL:
            {
                strStack.push(std::to_string(val1*val2));
                break;
            }
            case OPER::DIV:
            {
                strStack.push(std::to_string(val2/val1));
                break;
            }
        }
    }

    int evalRPN(vector<string>& tokens) 
    {
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+")
            {
                calculateAndUpdateStack(OPER::ADD);
            }
            else if(tokens[i] == "-")
            {
                calculateAndUpdateStack(OPER::SUB);
            }
            else if(tokens[i] == "*")
            {
                calculateAndUpdateStack(OPER::MUL);
            }
            else if(tokens[i] == "/")
            {
                calculateAndUpdateStack(OPER::DIV);
            }
            else
            {
                strStack.push(tokens[i]);
            }
        }
        
        int result = std::stoi(strStack.top());
        strStack.pop();
        return result;
    }
};
