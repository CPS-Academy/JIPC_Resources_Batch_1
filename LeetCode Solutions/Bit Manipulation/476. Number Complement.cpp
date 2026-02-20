class Solution {
public:
    int findComplement(int num) {
        // 110010
        // 111111
        // 001101 correct
        // 0000000000000000101
        // 1111111111111111010 x
        // num = ~num; // very wrong


        int all1 = 0;
        int n = num;
        while(n > 0){ // O(logn), to be precise num of bits in n
            n = n >> 1;


            all1 = all1 << 1;
            all1 = all1 | 1;
        }


        // return all1 - num;
        return all1 ^ num;
    }
};
