class Solution {
private:
    int INVALID = -1;
    vector<int> storeLis;
    int findLIS(int index, vector<int>& nums) {
        // Base case
        // if(index >= nums.size()) {
        //     return 0;
        // }
        // Memorization
        int& currentLis = storeLis[index];
        if(currentLis != INVALID) {
            return currentLis;
        }
        // Transition
        currentLis = 1;
        for(int j = index + 1; j < nums.size(); j++) {
            if(nums[index] < nums[j]) {
                currentLis = max(currentLis, 1 + findLIS(j, nums));
            }
        }
        return currentLis;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        storeLis.assign(nums.size(), INVALID);
        int maxLis = 0;
        for(int i = 0; i < nums.size(); i++) {
            maxLis = max(maxLis, findLIS(i, nums));
        }
        return maxLis;
    }
};
