class Solution {
    const int INVALID = -1;
    vector<int> ways;
    int findCombinations(int remainingTarget, vector<int>& nums) {
        if(remainingTarget == 0) {
            return 1;
        }
        if(remainingTarget < 0) {
            return 0;
        }
        int& currentCombination = ways[remainingTarget];
        if(currentCombination != INVALID) {
            return currentCombination;
        }

        currentCombination = 0;
        for(auto& num: nums) {
            currentCombination += findCombinations(remainingTarget - num, nums);
        }
        return currentCombiniation;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        ways.assign(target + 1, INVALID);
        return findCombinations(target, nums);
    }
};
