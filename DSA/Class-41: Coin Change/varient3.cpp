#include<bits/stdc++.h>
using namespace std;

vector<int> coins;
vector<vector<int>> dp;

int isPossibleToMakeChange(int index, int remaingAmount) { // (0, N)
    if(remaingAmount == 0) { // base case
        return 1;
    }
    if(index == coins.size() || remaingAmount < 0) { // base case
        return 0;
    }
    if(dp[index][remaingAmount] != -1) { // memorization
        return dp[index][remaingAmount];
    }

    int coinTaken = isPossibleToMakeChange(index + 1, remaingAmount - coins[index]);
    int coinNotTaken = isPossibleToMakeChange(index + 1, remaingAmount);

    return dp[index][remaingAmount] = (coinTaken + coinNotTaken);
}

int main()
{
    int N;
    cin >> N;

    int numberOfCoins;
    cin >> numberOfCoins;
    for(int i = 0; i < numberOfCoins; i++) {
        int coinValue;
        cin >> coinValue;
        coins.push_back(coinValue);
    }

    dp.assign(numberOfCoins, vector<int>(N + 1, -1));

    cout << isPossibleToMakeChange(0, N) << '\n';
}
