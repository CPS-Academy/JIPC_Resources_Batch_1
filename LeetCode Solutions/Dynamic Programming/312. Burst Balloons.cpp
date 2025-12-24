class Solution {
private:
    vector<vector<int>> maxCoinsInRange;
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        maxCoinsInRange.assign(n, vector<int>(n, 0));


        for(int len = 1; len <= n - 2; len++) { // len = 1, 2, 3, 4, ..., n - 2
            for(int L = 1, R = len; R + 1 < n; L++, R++) { // L,R = (1, len), (2, len + 1), (3, len + 2), ...., n - 2
                for(int target = L; target <= R; target++) { // target = L, L + 1, L + 2, ....., R - 2, R - 1, R
                    int coinsGainedFromTarget = nums[L - 1]*nums[R + 1]*nums[target]; // bursting in the sub-range is second priority
                    int maxCoinGainFromLeft = maxCoinsInRange[L][target - 1]; // burst this is top priority
                    int maxCoinGainFromRight = maxCoinsInRange[target + 1][R]; // burst this is top priority
                    int totalCoinGain = coinsGainedFromTarget + maxCoinGainFromLeft + maxCoinGainFromRight;
                    maxCoinsInRange[L][R] = max(maxCoinsInRange[L][R], totalCoinGain);
                }
            }
        }

        return maxCoinsInRange[1][n - 2];
    }
};

class Solution {
private:
    int INVALID = -1;
    vector<vector<int>> maxCoinsInRange;
    int findMaxCoins(int L, int R, vector<int>& nums) {
        if(L > R) { // base case
            return 0;
        }
        if(maxCoinsInRange[L][R] != INVALID) { // memorization
            return maxCoinsInRange[L][R];
        }
        maxCoinsInRange[L][R] = 0;
        int maxCoinsFromLAndR = nums[L - 1]*nums[R + 1];
        for(int target = L; target <= R; target++) {
            int coinsGainedFromTarget = maxCoinsFromLAndR*nums[target]; // bursting in the sub-range is second priority
            int maxCoinGainFromLeft = findMaxCoins(L, target - 1, nums); // burst this is top priority
            int maxCoinGainFromRight = findMaxCoins(target + 1, R, nums); // burst this is top priority
            int totalCoinGain = coinsGainedFromTarget + maxCoinGainFromLeft + maxCoinGainFromRight;
            maxCoinsInRange[L][R] = max(maxCoinsInRange[L][R], totalCoinGain);
        }

        return maxCoinsInRange[L][R];
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        maxCoinsInRange.assign(n, vector<int>(n, INVALID));


        // for(int i = 0; i < n; i++) {
        //     cout << nums[i] << ' ';
        // }
        // cout << '\n';
        return findMaxCoins(1, n - 2, nums); 
    }
};
