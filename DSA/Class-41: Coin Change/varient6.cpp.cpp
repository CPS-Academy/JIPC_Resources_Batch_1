#include<bits/stdc++.h>
using namespace std;

vector<int> coins;
vector<int> frequency;
vector<vector<int>> dp;

int waysToMakeChange(int index, int remaingAmount) { // (0, N)
    if(remaingAmount == 0) { // base case
        return 1;
    }
    if(index == coins.size() || remaingAmount < 0) { // base case
        return 0;
    }
    if(dp[index][remaingAmount] != -1) { // memorization
        return dp[index][remaingAmount];
    }

    int totalNumberOfWays = 0;
    for(int currFreq = 0; currFreq <= frequency[index] && currFreq*coins[index] <= remaingAmount; currFreq++) {
        totalNumberOfWays |= waysToMakeChange(index + 1, remaingAmount - currFreq*coins[index]);
    }

    return dp[index][remaingAmount] = totalNumberOfWays;
}

int main()
{
    int N;
    cin >> N;

    int numberOfCoins;
    cin >> numberOfCoins;
    for(int i = 0; i < numberOfCoins; i++) {
        int coinValue, freq;
        cin >> coinValue >> freq;
        coins.push_back(coinValue);
        frequency.push_back(freq);
    }

    dp.assign(numberOfCoins, vector<int>(N + 1, -1));

    cout << waysToMakeChange(0, N) << '\n';
}
