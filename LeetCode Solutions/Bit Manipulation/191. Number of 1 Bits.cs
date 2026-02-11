class Solution {
public:
    int hammingWeight(int n) {
        return hammingWeightBySetBits(n);
    }


    int hammingWeightByAllBits(int n){
        int countOfOne = 0;
        // time O(log(n))
        // to be exact, number of bits in n
        while(n > 0){
            if((n & 1) > 0) countOfOne++;
            n = n >> 1;
        }
        return countOfOne;
    }


    int hammingWeightBySetBits(int n){
        int countOfOne = 0;
        // time O(log(n))
        // to be exact, number of set bits in n
        // Brian Kerningham’s algorithm
        while(n > 0){
            n = n & (n - 1);
            countOfOne++;
        }
        return countOfOne;
    }
};
