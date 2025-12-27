class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefixSum = 0;
        int maxSumSubarray = INT_MIN;
        int minValueTillNow = 0;
        for(int R = 0; R < nums.size(); R++) {
            prefixSum += nums[R];
            maxSumSubarray = max(maxSumSubarray, prefixSum - minValueTillNow);
            minValueTillNow = min(minValueTillNow, prefixSum);
        }

        return maxSumSubarray;
    }
};
