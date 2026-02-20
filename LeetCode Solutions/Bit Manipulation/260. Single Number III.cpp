class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // [2, 5, 8, 5, 1, 8, 2, 7, 9, 9]


        int xorall = 0;
        for(int num: nums){
            xorall = xorall ^ num;
        }


        // xorall = 1 ^ 7
        // 1 = 001
        // 7 = 111
        // 6 = 110, 1 ^ 7


        int marker = xorall - (xorall & (xorall - 1));
        int xor0 = 0, xor1 = 0;
        for(int num: nums){
            if((marker & num) == 0) xor0 = xor0 ^ num;
            else xor1 = xor1 ^ num;
        }


        return vector<int>({xor0, xor1});


    }
};
