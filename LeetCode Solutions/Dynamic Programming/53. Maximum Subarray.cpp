class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentPrefixSum = 0;
        int minPrefixSum = 0;
        int maxSumSubArray = nums[0];
        for(auto& num: nums) {
            currentPrefixSum += num;
            maxSumSubArray = max(maxSumSubArray, currentPrefixSum - minPrefixSum);
            minPrefixSum = min(minPrefixSum, currentPrefixSum);
        }
        return maxSumSubArray;
    }

    /*
        int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int numsSize = nums.size();
        for(int L = 0; L < numsSize; L++) {
            for(int R = L; R < numsSize; R++) {
                int subArraySum = 0;
                for(int i = L; i <= R; i++) {
                    subArraySum += nums[i];
                }
                maxSum = max(maxSum, subArraySum);
            }
        }
        return maxSum;
    }

    int maxSubArray(vector<int>& nums) {

        vector<int> prefixSum;
        int currentPrefixSum = 0;
        prefixSum.push_back(currentPrefixSum);
        for(auto& num: nums) {
            currentPrefixSum += num;
            prefixSum.push_back(currentPrefixSum);
        }

        int prefixSumSize = prefixSum.size();
        int maxSum = nums[0];
        for(int L = 0; L < prefixSumSize; L++) {
            for(int R = L + 1; R < prefixSumSize; R++) {
                // cout << L << " " << R << " " << prefixSum[R] - prefixSum[L] << '\n';
                int subArraySum = prefixSum[R] - prefixSum[L];
                maxSum = max(maxSum, subArraySum);
            }
        }
        return maxSum;
    }

    int maxSubArray(vector<int>& nums) {

        vector<int> prefixSum;
        int currentPrefixSum = 0;
        for(auto& num: nums) {
            currentPrefixSum += num;
            prefixSum.push_back(currentPrefixSum);
        }

        int prefixSumSize = prefixSum.size();
        int maxSum = nums[0];
        int minPrefixSum = 0;
        for(int R = 0; R < prefixSumSize; R++) {
            int subArraySum = prefixSum[R] - minPrefixSum;
            minPrefixSum = min(minPrefixSum, prefixSum[R]);
            maxSum = max(maxSum, subArraySum);
        }
        return maxSum;
    }
    */
};
