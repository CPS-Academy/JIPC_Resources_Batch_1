class Solution {
private:
    int INVALID = -1;
    vector<int> minCostToReach;
    int findMinCost(int currentStep, vector<int>& cost) {
        // Base case
        if(cost.size() <= currentStep) {
            return 0;
        }
        // Memorization
        if(minCostToReach[currentStep] != INVALID) {
            return minCostToReach[currentStep];
        }

        // Transition
        int minCostTakingOneStep = findMinCost(currentStep + 1, cost);
        int minCostTakingTwoStep = findMinCost(currentStep + 2, cost);
        return minCostToReach[currentStep] = cost[currentStep] + min(minCostTakingOneStep, minCostTakingTwoStep);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        minCostToReach.assign(cost.size(), INVALID);
        return min(findMinCost(0, cost), findMinCost(1, cost));
    }
};
