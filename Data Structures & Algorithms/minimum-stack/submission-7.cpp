class MinStack {
public:
    std::stack<long> intStack;
    long minVal;

    MinStack()
    {
    }
    
    void push(int val) 
    {
        if(intStack.empty())
        {
            intStack.push(0);
            minVal = val;           
        }
        else
        {
            intStack.push(val-minVal);
            if (val < minVal) minVal = val;
        }
    }
    
    void pop() 
    {
        if(intStack.empty())
            return;

        if(intStack.top() < 0)
            minVal = minVal - intStack.top();

        intStack.pop();
    }
    
    int top() 
    {
        long top = intStack.top();
        if(top > 0)
            return top + minVal;
        else
            return (int)minVal; 
    }
    
    int getMin() 
    {
        return (int)minVal;
    }
};
