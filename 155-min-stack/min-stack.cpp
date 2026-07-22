class MinStack {
private:
    stack<int> stk;
    stack<int> minStk;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        stk.push(value);
        // first element or latest smallest value
        if(minStk.empty() || value <= minStk.top()) {
            minStk.push(value);
        }
    }
    
    void pop() {
        // if smallest curr is being popped
        if(stk.top() == minStk.top()) {
            minStk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */