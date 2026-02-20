class Solution {
public:
    void solve(vector<int> &nums, vector<int> &cur, vector<bool> &mask, vector<vector<int>> &ans) {
        if(nums.size() == cur.size()) {
            ans.push_back(cur);
            return;
        }

        for ( int i = 0; i < nums.size(); i++ ) {
            if(mask[i] == 0) {
                cur.push_back(nums[i]);
                mask[i] = 1;

                solve (nums, cur, mask, ans);

                cur.pop_back();
                mask[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        vector<bool> mask(nums.size(), 0);

        solve(nums, cur, mask, ans);
        return ans;
    }
};

