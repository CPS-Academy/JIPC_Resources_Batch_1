class Solution {
public:
    bool isPowerOfTwo(int n) {
        return isPowerOfTwo_Bitwise(n);
    }


    bool isPowerOfTwo_Math(int n) {
        if(n <= 0) return false;
        // n is positive
        // time O(log(n)), space O(1)
        while(n % 2 == 0){ // n is divisible by 2
            n = n / 2;
        }


        if(n > 1) return false;
        else return true;
    }


    bool isPowerOfTwo_Bitwise(int n) {
        if(n <= 0) return false;


        // n is positive
        // time O(1), space O(1)
        if( (n & (n - 1)) == 0) return true;
        else return false;
    }
};
