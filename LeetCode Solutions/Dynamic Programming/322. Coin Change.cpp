class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX/2);
        dp[0] = 0;
        for(int i = 0; i <= amount; i++) {
            for(auto& coin: coins) {
                if(coin <= amount && i + coin <= amount) {
                    dp[i + coin] = min(dp[i + coin], 1 + dp[i]);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }



    /*

    vector<int> dp;
    int findMinCoin(int remainingAmount, vector<int>& coins) {
        if(remainingAmount == 0) return 0;
        if(dp[remainingAmount] != -1) return dp[remainingAmount];
        int minCoinNeeded = INT_MAX/2;
        for(auto& coin: coins) {
            if(coin <= remainingAmount) {
                minCoinNeeded = min(minCoinNeeded, 1 + findMinCoin(remainingAmount - coin, coins));
            }
        }
        return dp[remainingAmount] = minCoinNeeded;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount + 1, -1);
        int minCoin = findMinCoin(amount, coins);
        return minCoin > amount ? -1 : minCoin;
    }

    */
};
