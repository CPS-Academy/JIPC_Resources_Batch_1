class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthestIndexToReach = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(furthestIndexToReach < i) return false;
            furthestIndexToReach = max(furthestIndexToReach, i + nums[i]);
        }
        return true;
    }
};
