class Solution {
public:
    void rotate(vector<int>& nums, int k) { // T.C: O(N) S.C: O(N) / O(1)
        int n = nums.size();
        k %= n;
        for(int i = 0; i + k < n; i++) {
            nums.push_back(nums[i]);
        }
        nums.erase(nums.begin(), nums.begin() + n - k);
    }
};
