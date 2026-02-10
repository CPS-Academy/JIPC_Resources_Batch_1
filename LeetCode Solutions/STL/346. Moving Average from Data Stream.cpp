class MovingAverage { // T.C: O(# of function calls) S.C: O(size)
private:
    int sum;
    int size;
    queue<int> q;
public:
    MovingAverage(int size) { // T.C: O(1) S.C: O(1)
        this->sum = 0;
        this->size = size;
    }
    
    double next(int val) { // T.C: O(1) S.C: O(1)
        if(q.size() >= this->size) {
            sum -= q.front();
            q.pop();
        }
        sum += val;
        q.push(val);
        return (1.0*sum)/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
