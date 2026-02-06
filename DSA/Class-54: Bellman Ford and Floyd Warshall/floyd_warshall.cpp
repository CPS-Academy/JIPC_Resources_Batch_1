#include<bits/stdc++.h>
using namespace std;

int minDist[1002][1002];

int main() {

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << i << " " << j << ":\n";
            cin >> minDist[i][j];
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int u = 1; u <= n; u++) {
            for(int v = 1; v <= n; v++) {
                minDist[u][v] = min(minDist[u][v], minDist[u][k] + minDist[k][v]);
            }
        }
    }

    for(int u = 1; u <= n; u++) {
        for(int v = 1; v <= n; v++) {
            cout << u << " " << v << " " << minDist[u][v] << '\n';
        }
    }
}
