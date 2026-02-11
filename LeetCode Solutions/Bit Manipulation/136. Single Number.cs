class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        // time O(n)
        // space O(1)
        for(int num: nums){
            x ^= num;
        }
        return x;
    }
};
