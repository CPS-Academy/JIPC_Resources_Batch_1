class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> maxPrevProfit;
        maxPrevProfit.assign(2, 0);

        for(int pos = 0; pos < nums.size(); pos++) {

            int maxProfitBySkippingCurrentHouse = max(maxPrevProfit[0], maxPrevProfit[1]);
            int maxProfitByRobbingCurrentHouse = nums[pos] + maxPrevProfit[0];

            maxPrevProfit[0] = maxProfitBySkippingCurrentHouse;
            maxPrevProfit[1] = maxProfitByRobbingCurrentHouse;
        }

        return max(maxPrevProfit[0], maxPrevProfit[1]);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> maxProfit;
        maxProfit.assign(2, vector<int>(nums.size() + 1, 0));

        for(int pos = 0; pos < nums.size(); pos++) {
            maxProfit[0][pos + 1] = max(maxProfit[0][pos], maxProfit[1][pos]);
            maxProfit[1][pos + 1] = nums[pos] + maxProfit[0][pos];
        }

        return max(maxProfit[0][nums.size()], maxProfit[1][nums.size()]);
    }
};

class Solution {
private:
    int INVALID = -1;

    vector<vector<int>> maxProfit;
    int findMaxAmount(int currentPosition, int isPrevHouseRobbed, vector<int>& nums) {
        if(currentPosition == nums.size()) return 0;
        if(maxProfit[currentPosition][isPrevHouseRobbed] != INVALID) return maxProfit[currentPosition][isPrevHouseRobbed];

        int maxProfitByRobbingCurrentHouse = INT_MIN;
        if(!isPrevHouseRobbed) {
            maxProfitByRobbingCurrentHouse = nums[currentPosition] + findMaxAmount(currentPosition + 1, 1, nums);
        }
        int maxProfitBySkippingCurrentHouse = findMaxAmount(currentPosition + 1, 0, nums);

        return maxProfit[currentPosition][isPrevHouseRobbed] = max(maxProfitByRobbingCurrentHouse, maxProfitBySkippingCurrentHouse);
    }
public:
    int rob(vector<int>& nums) {
        maxProfit.assign(nums.size(), vector<int>(2, INVALID));
        return findMaxAmount(0, 0, nums);
    }
};
