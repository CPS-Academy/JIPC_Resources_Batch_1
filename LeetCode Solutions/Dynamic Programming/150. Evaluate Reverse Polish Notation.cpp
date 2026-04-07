class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> operations = {
            {"+", [](int a, int b) {return a + b;}},
            {"-", [](int a, int b) {return a - b;}},
            {"*", [](int a, int b) {return a * b;}},
            {"/", [](int a, int b) {return a / b;}},
        };
        stack<int> operands;
        for(string& token: tokens) {
            if(!operations.count(token)) {
                int numericValue = stoi(token);
                operands.push(numericValue);
                continue;
            }
            int operand2 = operands.top(); operands.pop();
            int operand1 = operands.top(); operands.pop();
            function<int(int, int)> operation = operations[token];
            int result = operation(operand1, operand2);
            operands.push(result);
        }
        return operands.top();
    }
};
