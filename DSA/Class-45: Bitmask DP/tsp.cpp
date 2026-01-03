#include<bits/stdc++.h>
using namespace std;

int n, distGraph[4][4];
int dp[20][1 << 20];

bool checkBit(int mask, int pos) {
    return (mask& (1 << pos));
}

int updateBit(int mask, int pos) {
    return (mask| (1 << pos));
}

int tsp(int currentHouse, int mask) {

    // Base Case
    if (mask + 1 == (1 << n)) {
        return 0;
    }
    // Memorization
    if(dp[currentHouse][mask] != -1) {
        return dp[currentHouse][mask];
    }

    // Transition
    int minCost = 100000009;
    for(int next = 0; next < n; next++) {
        if(checkBit(mask, next) == 0) {
            int value = distGraph[currentHouse][next]
                        + tsp(next, updateBit(mask, next));
            minCost = min(minCost, value);
        }
    }

    return dp[currentHouse][mask] = minCost;
}

// T.C: O(N^2 * 2^N)
// S.C: O(N* 2^N)

int main()
{
    n = 4;
    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0},
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            distGraph[i][j] = graph[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }

    cout << tsp(0, 1) << '\n';

    return 0;
}
