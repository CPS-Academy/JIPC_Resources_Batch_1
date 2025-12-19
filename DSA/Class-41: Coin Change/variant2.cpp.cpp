#include<bits/stdc++.h>
using namespace std;

vector<int> coins;
vector<int> dp;

int findNumberOfways(int remaingAmount) { /// 11
    if(remaingAmount < 0) { // base case
        return 0;
    }
    if(remaingAmount == 0) { // base case
        return 1;
    }
    if(dp[remaingAmount] != -1) { // memorization
        return dp[remaingAmount];
    }

    int sumOfPossibleWays = 0;
    for(int i = 0; i < coins.size(); i++) { /// 10, 9, 6 [1, 2, 5]
        sumOfPossibleWays += findNumberOfways(remaingAmount - coins[i]);
    }

    return dp[remaingAmount] = sumOfPossibleWays;
}

int main()
{
    int N;
    cin >> N;

    dp.assign(N + 1, -1);

    int numberOfCoins;
    cin >> numberOfCoins;
    for(int i = 0; i < numberOfCoins; i++) {
        int coinValue;
        cin >> coinValue;
        coins.push_back(coinValue);
    }

    cout << findNumberOfways(N) << '\n';
}
