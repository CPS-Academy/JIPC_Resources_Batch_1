#include<bits/stdc++.h>
using namespace std;

int n, weights[102], price[102], dp[102][102];

int fun(int pos, int remCapa) { /// fun(current Position, remaining Capacity of bag)
    if(pos == n) { // base case
        return 0;
    }
    if(dp[pos][remCapa] != -1) return dp[pos][remCapa];

    int pick = 0;
    if(remCapa >= weights[pos]) {
        pick = price[pos] + fun(pos + 1, remCapa - weights[pos]);
    }
    int dontPick = fun(pos + 1, remCapa);

    return dp[pos][remCapa] = max(pick, dontPick);
}

int main()
{
    int capacity;
    cin >> capacity >> n;

    memset(dp, -1, sizeof dp);

    for(int i = 0; i < n; i++) {
        cin >> price[i] >> weights[i];
    }

    cout << fun(0, capacity) << '\n';

    // T.C: O(N*capacity)
    // S.C: O(N*capacity)

    return 0;
}
