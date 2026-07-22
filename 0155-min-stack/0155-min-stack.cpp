class MinStack {
public:
    MinStack() 
    {
    }
    
    void push(int value) 
    {
        dataStack.push(value);

        if (minStack.empty() || value <= minStack.top())
        {
            minStack.push(value);
        }
        else
        {
            minStack.push(minStack.top());
        }
    }
    
    void pop() 
    {
        dataStack.pop();
        minStack.pop();
    }
    
    int top() 
    {
        return dataStack.top();
    }
    
    int getMin() 
    {
        return minStack.top();
    }

private:
    std::stack<int> dataStack;
    std::stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */