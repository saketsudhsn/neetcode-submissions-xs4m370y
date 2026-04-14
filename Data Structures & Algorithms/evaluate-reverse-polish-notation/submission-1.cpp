class Solution {
public:

    int evalRPN(vector<string>& tokens) 
    {
        std::string token = tokens.back();
        tokens.pop_back();
        
        if(token != "+" && token != "-" && token != "*" && token != "/")
        {
            return std::stoi(token);
        }

        int right   = evalRPN(tokens);
        int left    = evalRPN(tokens);
        if(token == "+")
        {
            return left + right;
        }
        if(token == "-")
        {
            return left - right;
        }
        if(token == "*")
        {
            return left * right;
        }
        if(token == "/")
        {
            return left / right;
        }
    }
};
