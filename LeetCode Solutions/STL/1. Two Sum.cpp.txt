class Solution {
private:
    int INVALID = -1;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> previousValue_indexMap;
        for(int i = 0; i < nums.size(); i++) {
            int currentValue = nums[i];
            int complementValue = target - currentValue;
            if(previousValue_indexMap.count(complementValue)) {
                return {i, previousValue_indexMap[complementValue]};
            }
            previousValue_indexMap[currentValue] = i;
        }
        return {INVALID};
    }
};

class Solution {
private:
    int INVALID = -1;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {INVALID};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexPair;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    indexPair = {i, j};
                    break;
                }
                if(indexPair.size() != 0) {
                    break;
                }
            }
        }
        return indexPair;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexPair;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    indexPair = {i, j};
                    break;
                }
                if(indexPair.size() != 0) {
                    break;
                }
            }
        }
        return indexPair;
    }
};
