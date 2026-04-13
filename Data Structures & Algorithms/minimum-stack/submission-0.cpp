class MinStack {
public:
    std::vector<int> intStack;
    MinStack()
    {
    }
    
    void push(int val) 
    {
        intStack.push_back(val);
    }
    
    void pop() {
        intStack.pop_back();
    }
    
    int top() 
    {
        return intStack[intStack.size()-1];  
    }
    
    int getMin() 
    {
        int minVal = intStack[0]; 
        for(auto val : intStack)
        {
            minVal = min(minVal, val);
        }

        return minVal;
    }
};
