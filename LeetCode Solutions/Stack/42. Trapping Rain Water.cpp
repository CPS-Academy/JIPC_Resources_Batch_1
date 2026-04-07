class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0, R = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int trappedWaterAmount = 0;
        while(L < R) {
            if(height[L] < height[R]) {
                if(height[L] < leftMax) {
                    trappedWaterAmount += min(height[R], leftMax) - height[L];
                }
                else leftMax = height[L];
                L++;
            }
            else {
                if(height[R] < rightMax) {
                    trappedWaterAmount += min(height[L], rightMax) - height[R];
                }
                else rightMax = height[R];
                R--;
            }
        }
        return trappedWaterAmount;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax;
        int currentLeftMax = 0;
        for(auto& value: height) {
            leftMax.push_back(currentLeftMax);
            currentLeftMax = max(currentLeftMax, value);
        }
        int totalAmountOfWater = 0;
        int currentRightMax = 0;
        for(int i = height.size() - 1; i >= 0; i--) {
            totalAmountOfWater += max(0, min(leftMax[i], currentRightMax) - height[i]);
            currentRightMax = max(currentRightMax, height[i]);
        }
        return totalAmountOfWater;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax;
        int currentLeftMax = 0;
        for(auto& value: height) {
            leftMax.push_back(currentLeftMax);
            currentLeftMax = max(currentLeftMax, value);
        }
        int result = 0;
        int currentRightMax = 0;
        for(int i = height.size() - 1; i >= 0; i--) {
            result += max(0, min(currentRightMax, leftMax[i]) - height[i]);
            currentRightMax = max(currentRightMax, height[i]);
        }
        return result;
    }
};
