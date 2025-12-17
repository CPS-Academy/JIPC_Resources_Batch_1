class Solution {
private:
    vector<int> lowerBoundFindingArray;
    int findLisEndingAt(vector<int> nums, int index) {
        int lo = 0, hi = nums.size();
        int lowerBound;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(nums[index] <= lowerBoundFindingArray[mid]) {
                hi = mid - 1;
                lowerBound = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        lowerBoundFindingArray[lowerBound] = nums[index];
        return lowerBound;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        lowerBoundFindingArray.assign(nums.size() + 1, INT_MAX);
        lowerBoundFindingArray[0] = INT_MIN;

        int maxLIS = 1;
        for(int i = 0; i < nums.size(); i++) {
            maxLIS = max(maxLIS, findLisEndingAt(nums, i));
        }
        return maxLIS;
    }
};

class Solution {
private:
    vector<int> lowerBoundFindingArray;
    int binarySearch(vector<int> nums, int index) {
        int lo = 0, hi = nums.size();
        int lowerBound;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(nums[index] <= lowerBoundFindingArray[mid]) {
                hi = mid - 1;
                lowerBound = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        lowerBoundFindingArray[lowerBound] = nums[index];
        return lowerBound;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        lowerBoundFindingArray.assign(nums.size() + 1, INT_MAX);
        lowerBoundFindingArray[0] = INT_MIN;

        int maxLIS = 1;
        for(int i = 0; i < nums.size(); i++) {
            maxLIS = max(maxLIS, binarySearch(nums, i));
        }
        return maxLIS;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(), 1);
        int maxLIS = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            LIS[i] = 1;
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] < nums[j]) {
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
            maxLIS = max(maxLIS, LIS[i]);
        }
        return maxLIS;
    }
};
