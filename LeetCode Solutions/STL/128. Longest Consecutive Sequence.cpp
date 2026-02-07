class Solution {
public:
    int longestConsecutive(vector<int>& nums) { // T.C: O(NlogN) S.C: O(N)
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int maxSequenceLength = (nums.size() != 0);
        for(auto num: nums_set) {
            if(!nums_set.count(num - 1)) {
                int currentSequenceLength = 0;
                for(int currentNum = num; nums_set.count(currentNum) != 0; currentNum++) {
                    currentSequenceLength++;
                }
                maxSequenceLength = max(maxSequenceLength, currentSequenceLength);
            }
        }
        return maxSequenceLength;
    }
};

