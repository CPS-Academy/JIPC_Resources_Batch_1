class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool isOneExist = false;
        for(auto& num: nums) {
            if(num == 1) {
                isOneExist = true;
            }
            if(num <= 0) {
                num = 1;
            }
        }
        if(!isOneExist) {
            return 1;
        }

        for(int i = 0; i < nums.size(); i++) {
            int value = abs(nums[i]) - 1;
            if(value < nums.size()) {
                int index = value;
                nums[index] = -abs(nums[index]);
            }
        }

        int firstMissingPositiveNumber = nums.size() + 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                firstMissingPositiveNumber = i + 1;
                break;
            }
        }
        return firstMissingPositiveNumber;
    }
};



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> nums_set;
        for(auto& num: nums) {
            nums_set.insert(num);
        }
        int num = 1;
        int firstMissingPositiveNumber;
        while(true) {
            if(!nums_set.count(num)) {
                firstMissingPositiveNumber = num;
                break;
            }
            num++;
        }
        return firstMissingPositiveNumber;
    }
};



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> seen(nums.size() + 1, false);
        for(auto& num: nums) {
            if(0 < num && num <= nums.size()) {
                seen[num] = true;
            }
        }
        int firstMissingPositiveNumber = nums.size() + 1;
        for(int i = 1; i < seen.size(); i++) {
            if(!seen[i]) {
                firstMissingPositiveNumber = i;
                break;
            }
        }
        return firstMissingPositiveNumber;
    }
};
