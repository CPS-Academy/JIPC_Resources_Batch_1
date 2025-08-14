// 1. Naive approach

class Solution {
public:
    int addDigits(int num) {
        int digitSum = 0;

        while (num > 0) {
            digitSum += num % 10;
            num /= 10;

            if ( num == 0 && digitSum > 9 ) {
                num = digitSum;
                digitSum = 0;
            }
        }

        return digitSum;
    }
};

// 2. Recursive Approach

class Solution {
public:
    int solve(int num) {
        if(num <= 9) return num;
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }

        return solve(digitSum);
    }

    int addDigits(int num) {
        return solve(num);
    }
};
