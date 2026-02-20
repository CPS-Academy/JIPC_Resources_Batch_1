class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // [0, 1, 2, ...5, 7, 8]
        // [1, 1, 1,    1, 0, 1, 1] // O(n) space, O(n) time




        // [0, 1, 2, ...5, 7, 8] ^
        // [0, 1, 2, ...5, 6, 7, 8] ^
        int xorall = 0;
        for(int num : nums){
            xorall = xorall ^ num;
        }
        for(int i = 0; i <= nums.size(); i++){
            xorall = xorall ^ i;
        }


        return xorall;
    }
};
