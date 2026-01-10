class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int minCostOfPreviousStep = 0;
        int minCostOfPreviousOfPreviousStep = 0;
        for(int i = 2; i <= cost.size(); i++) {
            int currentMinCost = min(minCostOfPreviousStep + cost[i - 1], minCostOfPreviousOfPreviousStep + cost[i - 2]);
            minCostOfPreviousOfPreviousStep = minCostOfPreviousStep;
            minCostOfPreviousStep = currentMinCost;
        }
        return minCostOfPreviousStep;
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minCost(cost.size() + 1, 0);
        for(int i = 2; i <= cost.size(); i++) {
            minCost[i] = min(minCost[i - 1] + cost[i - 1], minCost[i - 2] + cost[i - 2]);
        }
        return minCost[ cost.size() ];
    }
};

class Solution {
private:
    const int INVALID = -1;
    vector<int> minCostStore;
    int findMinCost(int currentStair, vector<int>& cost) {
        if(currentStair >= cost.size()) {
            return 0;
        }
        int& minCost = minCostStore[currentStair];
        if(minCost != INVALID) {
            return minCost;
        }
        return minCost = cost[currentStair] + min(findMinCost(currentStair + 1, cost), findMinCost(currentStair + 2, cost));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        minCostStore.assign(cost.size(), INVALID);
        return min(findMinCost(0, cost), findMinCost(1, cost));
    }
};
