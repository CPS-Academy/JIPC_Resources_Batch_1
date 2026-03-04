class MyStack {
private:
    queue<int> primaryQueue, backupQueue;
public:
    MyStack() {
        while(!primaryQueue.empty()) {
            primaryQueue.pop();
        }
    }
    
    void push(int x) {
        primaryQueue.push(x);
    }
    
    int pop() {
        while(primaryQueue.size() > 1) {
            backupQueue.push(primaryQueue.front());
            primaryQueue.pop();
        }
        int poppedValue = primaryQueue.front();
        primaryQueue.pop();
        swap(primaryQueue, backupQueue);
        return poppedValue;
    }
    
    int top() {
        int topValue = this->pop();
        primaryQueue.push(topValue);
        return topValue;
    }
    
    bool empty() {
        return primaryQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
