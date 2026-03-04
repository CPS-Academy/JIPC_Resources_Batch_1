class MyQueue {
private:
    stack<int> stack1, stack2;
public:
    MyQueue() {
        while(!stack1.empty()) {
            stack1.pop();
        }
        while(!stack2.empty()) {
            stack2.pop();
        }
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        this->peek();
        int poppedValue = stack2.top();
        stack2.pop();
        return poppedValue;
    }
    
    int peek() {
        if(stack2.empty()) {
            while(!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
