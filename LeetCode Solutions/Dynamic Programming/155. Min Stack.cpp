class MinStack {
private:
    stack<int> currentStack;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        currentStack.push(val);
        if(minStack.empty() || minStack.top() >= val) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if(!minStack.empty() && minStack.top() == currentStack.top()) {
            minStack.pop();
        }
        currentStack.pop();
    }
    
    int top() {
        return currentStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
