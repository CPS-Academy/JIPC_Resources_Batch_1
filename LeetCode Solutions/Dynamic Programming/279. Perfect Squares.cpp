class Solution {
private:
    int INVALID = -1;
    vector<int> perfectSquareCountStore;

public:
    int numSquares(int n) { // O(N*sqrt(N))
        perfectSquareCountStore.assign(n + 1, INVALID);
        
        perfectSquareCountStore[0] = 0;
        for(int number = 1; number <= n; number++) {
            perfectSquareCountStore[number] = INT_MAX;
            for(int i = 1; i*i <= number; i++) {
                perfectSquareCountStore[number] = min(perfectSquareCountStore[number], 1 + perfectSquareCountStore[number - i*i]);
            }
        }

        return perfectSquareCountStore[n];
    }
};


    // int findMinPerfectSquares(int value) { // O(N)
    //     if(value == 0 ){
    //         return 0;
    //     }

        // int& minSquareCount = perfectSquareCountStore[value];
        // if(minSquareCount != INVALID) {
        //     return minSquareCount;
        // }

        // minSquareCount = INT_MAX;
        // for(int numbers = 1; numbers*numbers <= value; numbers++) { // O(sqrt(N))
        //     minSquareCount = min(minSquareCount, 1 + findMinPerfectSquares(value - numbers*numbers));
        // }

        // return minSquareCount;
    // }
