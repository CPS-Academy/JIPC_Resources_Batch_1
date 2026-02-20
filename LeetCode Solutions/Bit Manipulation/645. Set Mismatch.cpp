class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // [1, 2, 3,   4, 5] = all
        // [1, 2, 2,   5, 4] = nums


        // soln 1
        // use visited array [1, 1?, 0, 1] O(n) space, time


        // soln 2, O(1) space, O(n) time
        // xorall 2^3


        int n = nums.size();
        int xorall = 0;
        for(int num: nums){
            xorall = xorall ^ num;
        }
        for(int i = 1; i <= n; i++){
            xorall = xorall ^ i;
        }


        // xorall is 2 ^ 3
        int marker = xorall - (xorall & (xorall-1));
        int xor0 = 0, xor1 = 0;


        for(int num: nums){
            if((num & marker) == 0) xor0 = xor0 ^ num;
            else xor1 = xor1 ^ num;
        }
        for(int i = 1; i <= n; i++){
            if((i & marker) == 0) xor0 = xor0 ^ i;
            else xor1 = xor1 ^ i;
        }


        for(int num: nums){
            if(num == xor0){
                return vector<int>({xor0, xor1});
            }
        }
        return vector<int>({xor1, xor0});
    }
};
