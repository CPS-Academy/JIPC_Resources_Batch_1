class Solution {
public:
    bool isPalindrome(int x){
        if(x < 0) return false;
        if(x == 0) return true;


       
        // x is positive
        // let x = 453, 21......9
        // x_r   = 354, 9......12
        int last;
        long long int x_r = 0;
        int x_c = x;
        while(x_c > 0){ // O(number of digits in x), O(log(x))
            last = x_c % 10;        //   3,   5,   4
            x_c = x_c / 10;         // 45,   4,   0
            x_r = x_r * 10 + last;  // 3,   35, 354
            // delete from right of x, insert in right of x_r
        }
        // last = 4, leftmost digit of x
        // x_c = 0
        // x_r = 354


        if((long long int) x == x_r) return true;
        else return false;
    }
};
