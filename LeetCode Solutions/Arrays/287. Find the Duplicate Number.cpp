class Solution {
public:
    int findDuplicate(vector<int>& nums) { // T.C: O(N) and S.C: O(N) / O(1)
        int tortoise = nums[nums[0]];
        int hare = nums[nums[nums[0]]];
        while(tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }

        tortoise = nums[0];
        while(tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> distinctNums;
        int duplicateNumber;
        for(auto& num: nums) {
            if(distinctNums.count(num)) {
                duplicateNumber = num;
                break;
            }
            else {
                distinctNums.insert(num);
            }
        }
        return duplicateNumber;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> distinctNums;
        int duplicateNumber;
        for(auto& num: nums) {
            if(distinctNums.count(num)) {
                duplicateNumber = num;
            }
            else {
                distinctNums.insert(num);
            }
        }
        return duplicateNumber;
    }
};
