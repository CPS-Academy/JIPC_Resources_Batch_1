class Solution {
private:
    int INVALID = -1;
    vector<vector<int>> storeNumberOfWays;
    int findNumberOfWays(int index, int remainingAmount, vector<int>& coins) {
        if(remainingAmount == 0) {
            return 1;
        }
        if(index == coins.size()) {
            return 0;
        }
        
        int& ways = storeNumberOfWays[index][remainingAmount];
        if(ways != INVALID) {
            return ways;
        }

        int takeCurrentCoin = 0;
        if(remainingAmount >= coins[index]) {
            takeCurrentCoin = findNumberOfWays(index, remainingAmount - coins[index], coins);
        }
        int dontTakeCurrentCoin = findNumberOfWays(index + 1, remainingAmount, coins);

        return ways = takeCurrentCoin + dontTakeCurrentCoin;
    }
public:
    int change(int amount, vector<int>& coins) {
        storeNumberOfWays.assign(coins.size(), vector<int>(amount + 1, INVALID));
        return findNumberOfWays(0, amount, coins);
    }
};
