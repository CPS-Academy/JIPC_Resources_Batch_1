class Solution {
private:
    vector<int> fibonacciNumber;
    int findFibonacciNumber(int n) {
        if(n < 2) return n;
        if(fibonacciNumber[n] != -1) return fibonacciNumber[n];
        return fibonacciNumber[n] = fib(n - 1) + fib(n - 2);
    }
public:
    int fib(int n) {
        fibonacciNumber.assign(n + 1, -1);
        return findFibonacciNumber(n);
    }
};
