class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int temp_max = max({curr, max_so_far * curr, min_so_far * curr});
            int temp_min = min({curr, max_so_far * curr, min_so_far * curr});

            max_so_far = temp_max;
            min_so_far = temp_min;
            
            result = max(max_so_far, result);
        }

        return result;
    }
};
