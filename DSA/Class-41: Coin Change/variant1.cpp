#include<bits/stdc++.h>
using namespace std;

vector<int> coins;
vector<int> dp;

bool isPossibleToMakeChange(int remaingAmount) { /// 11
    if(remaingAmount < 0) { // base case
        return false;
    }
    if(remaingAmount == 0) { // base case
        return true;
    }
    if(dp[remaingAmount] != -1) { // memorization
        return dp[remaingAmount];
    }

    bool isPossible = false;
    for(int i = 0; i < coins.size(); i++) { /// 10, 9, 6 [1, 2, 5]
        isPossible |= isPossibleToMakeChange(remaingAmount - coins[i]);
    }

    return dp[remaingAmount] = isPossible;
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

    cout << isPossibleToMakeChange(N) << '\n';
}
