class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int smallestCostOfBuying = prices[0];
        for(int sellingIndex = 1; sellingIndex < prices.size(); sellingIndex++) {
            maxProfit = max(maxProfit, prices[sellingIndex] - smallestCostOfBuying);
            smallestCostOfBuying = min(smallestCostOfBuying, prices[sellingIndex]);
        } 
        return maxProfit;
    }
};
