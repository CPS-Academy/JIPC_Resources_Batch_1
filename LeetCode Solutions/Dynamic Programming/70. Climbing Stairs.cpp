class Solution {
public:
    int climbStairs(int n) {
        int numberOfWaysFromPreviousStair = 1;
        int numberOfWaysFromPreviousOfPreviousStair = 1;
        for(int i = 2; i <= n; i++) {
            int numberOfWaysFromCurrentStair = numberOfWaysFromPreviousStair + numberOfWaysFromPreviousOfPreviousStair;
            numberOfWaysFromPreviousOfPreviousStair  = numberOfWaysFromPreviousStair;
            numberOfWaysFromPreviousStair = numberOfWaysFromCurrentStair;
        }
        return numberOfWaysFromPreviousStair;
    }
};

// prevOfPrev, prev      , (current) .....
// XXXXXXXXXX, prevOfPrev, prev, (current)
