class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> valueToGreaterValueOnRightMap;
        stack<int> nextGreaterElementStack;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!nextGreaterElementStack.empty() && nextGreaterElementStack.top() < nums2[i]) {
                nextGreaterElementStack.pop();
            }
            if(nextGreaterElementStack.empty()) {
                valueToGreaterValueOnRightMap[ nums2[i] ] = -1;
            }
            else {
                valueToGreaterValueOnRightMap[ nums2[i] ] = nextGreaterElementStack.top();
            }
            nextGreaterElementStack.push(nums2[i]);
        }

        vector<int> nextGreaterValues;
        for(auto& num: nums1) {
            nextGreaterValues.push_back(valueToGreaterValueOnRightMap[num]);
        }
        return nextGreaterValues;
    }
};


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> valueToGreaterValueOnRightMap;
        for(int i = 0; i < nums2.size(); i++) {
            int firstGreaterValueOnRight = -1;
            for(int j = i + 1; j < nums2.size(); j++) {
                if(nums2[i] < nums2[j]) {
                    firstGreaterValueOnRight = nums2[j];
                    break;
                }
            }
            valueToGreaterValueOnRightMap[ nums2[i] ] = firstGreaterValueOnRight;
        }

        vector<int> nextGreaterValues;
        for(auto& num: nums1) {
            nextGreaterValues.push_back(valueToGreaterValueOnRightMap[num]);
        }
        return nextGreaterValues;
    }
};
