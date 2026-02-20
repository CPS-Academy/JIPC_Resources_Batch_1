Recursive Solution:


class Solution {
public:
    void solve (vector<int> &cur, int next, vector<int> &nums, vector<vector<int>> &ans ) {
        ans.push_back(cur);
        if (next == nums.size()) return;

        for ( int i = next; i < nums.size(); i++ ) {
            cur.push_back(nums[i]);
            solve ( cur, i+1, nums, ans );
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        solve(cur, 0, nums, ans);

        return ans;
    }
};



Without Recursion:

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;

        ans.push_back(cur);

        for ( auto u : nums ) {
            vector<vector<int>> tmp = ans;

            for ( auto v : tmp ) {
                cur = v;
                cur.push_back(u);
                ans.push_back(cur);
            }
        }

        return ans;
    }
};
