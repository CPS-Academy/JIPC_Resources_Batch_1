class MyCircularQueue {
private:
    vector<int> queue;
    int frontPointer;
    int queueSize;
    int queueCapacity;

    int findIndex(int index) {
        if(index >= queueCapacity) return index - queueCapacity;
        // if(index < 0) return index + queueCapacity;
        return index;
    }

public:
    MyCircularQueue(int k) {
        queue.assign(k, -1);
        frontPointer = 0;
        queueSize = 0;
        queueCapacity = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        queue[ findIndex(frontPointer + queueSize) ] = value;
        queueSize++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        frontPointer = findIndex(frontPointer + 1);
        queueSize--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : queue[frontPointer];
    }
    
    int Rear() {
        return isEmpty() ? -1 : queue[ findIndex(frontPointer + queueSize - 1) ];
    }
    
    bool isEmpty() {
        return queueSize == 0;
    }
    
    bool isFull() {
        return queueSize == queueCapacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

class MyCircularQueue {
private:
    vector<int> queue;
    int frontPointer;
    int queueSize;
    int queueCapacity;
public:
    MyCircularQueue(int k) {
        queue.assign(k, -1);
        frontPointer = 0;
        queueSize = 0;
        queueCapacity = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        queue[ (frontPointer + queueSize) %queueCapacity ] = value;
        queueSize++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        frontPointer = (frontPointer + 1) %queueCapacity;
        queueSize--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : queue[frontPointer];
    }
    
    int Rear() {
        return isEmpty() ? -1 : queue[ (frontPointer + queueSize - 1) %queueCapacity ];
    }
    
    bool isEmpty() {
        return queueSize == 0;
    }
    
    bool isFull() {
        return queueSize == queueCapacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
