class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> valueStack;
        for(auto& operation: operations) {
            if(operation == "+") {
                int topValue = valueStack.top(); valueStack.pop();
                int secondTopValue = valueStack.top(); valueStack.pop();
                int sum = topValue + secondTopValue;
                valueStack.push(secondTopValue);
                valueStack.push(topValue);
                valueStack.push(sum);
            }
            else if(operation == "C") {
                valueStack.pop();
            }
            else if(operation == "D") {
                int doubledTopValue = valueStack.top()*2;
                valueStack.push(doubledTopValue);
            }
            else {
                int value = stoi(operation);
                valueStack.push(value);
            }
        }

        int totalSum = 0;
        while(!valueStack.empty()) {
            totalSum += valueStack.top();
            valueStack.pop();
        }
        return totalSum;
    }
};

