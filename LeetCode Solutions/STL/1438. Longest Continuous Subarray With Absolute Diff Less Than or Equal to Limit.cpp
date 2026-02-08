class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxValueDeque, minValueDeque;
        int longestSubarrayLength = 0;
        for(int L = 0, R = 0; R < nums.size(); R++) {
            int num = nums[R];
            while(!maxValueDeque.empty() && maxValueDeque.back() < num) {
                maxValueDeque.pop_back();
            }
            maxValueDeque.push_back(num);
            while(!minValueDeque.empty() && minValueDeque.back() > num) {
                minValueDeque.pop_back();
            }
            minValueDeque.push_back(num);

            while(maxValueDeque.front() - minValueDeque.front() > limit) {
                if(maxValueDeque.front() == nums[L]) {
                    maxValueDeque.pop_front();
                }
                if(minValueDeque.front() == nums[L]) {
                    minValueDeque.pop_front();
                }
                L++;
            }

            longestSubarrayLength = max(longestSubarrayLength, R - L + 1);
        }
        return longestSubarrayLength;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int L = 0, R = 0;
        multiset<int> valuesInRangeSet;
        int longestSubarrayLength = 0;
        while(R < nums.size()) {
            valuesInRangeSet.insert(nums[R]);
            R++;
            while(*(--valuesInRangeSet.end()) - *valuesInRangeSet.begin() > limit) {
                valuesInRangeSet.erase(valuesInRangeSet.find(nums[L]));
                L++;
            }
            longestSubarrayLength = max(longestSubarrayLength, R - L);
        }
        return longestSubarrayLength;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int longestSubarrayLength = 0;
        for(int L = 0; L < nums.size(); L++) {
            int maxValue = INT_MIN, minValue = INT_MAX;
            for(int R = L; R < nums.size(); R++) {
                maxValue = max(maxValue, nums[R]);
                minValue = min(minValue, nums[R]);
                if(maxValue - minValue > limit) {
                    break;
                }
                longestSubarrayLength = max(longestSubarrayLength, R - L + 1);
            }
        }
        return longestSubarrayLength;
    }
};
