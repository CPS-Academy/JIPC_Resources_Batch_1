class Solution {
public:
    int hammingDistance(int x, int y) {
        // x = 00..11
        // y = 00..01


        // count of mismatched bits in x and y
        // is equivalent to
        // count of 1 in x^y
        return countNumOf1(x^y);
    }


    int countNumOf1(int n){
        int count = 0;
        // O(log(n))
        // but to be exact, O(number of set bits in n)
        while(n > 0){
            n = n & (n - 1); // clearing the rightmost 1
            count++;
        }
        return count;
    }
};
