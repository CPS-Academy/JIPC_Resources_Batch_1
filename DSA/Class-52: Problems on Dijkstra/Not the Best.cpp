#include<bits/stdc++.h>
#define K 2
#define pii pair<long long, long long>
using namespace std;

long long n;
vector<long long> edge[100005], cost[100005];
vector<long long> minDistance[5003];

int main() {
    long long t, cas = 1, line;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &n, &line);
        while(line--) {
            long long u, v, c;
            scanf("%lld %lld %lld", &u, &v, &c);
            edge[u].push_back(v); cost[u].push_back(c);
            edge[v].push_back(u); cost[v].push_back(c);
        }

        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        minHeap.push({0, 1});

        while(!minHeap.empty()) {
            pii u = minHeap.top(); minHeap.pop();
            long long minCost = u.first;
            long long currentNode = u.second;

            if(minDistance[currentNode].empty() || (minDistance[currentNode].size() < K && minDistance[currentNode].back() < minCost)) {
                minDistance[currentNode].push_back(minCost);
            }

            for(int i = 0; i < (int)edge[currentNode].size(); i++) {
                long long nextNode = edge[currentNode][i];
                long long nextNodeWeight = cost[currentNode][i];

                if(minDistance[nextNode].size() < K) {
                    minHeap.push({minCost + nextNodeWeight, nextNode});
                }
            }
        }

        printf("Case %lld: %lld\n", cas++, minDistance[n].back());

        for(int i = 0; i <= n; i++) {
            edge[i].clear();
            cost[i].clear();
            minDistance[i].clear();
        }
    }
}

/*

Input:
1
2 4
1 2 2
1 2 5
1 2 6
1 2 2

Output;
node: 1 minCost: 0
node: 2 minCost: 2
node: 2 minCost: 2
node: 1 minCost: 4
node: 1 minCost: 4
node: 1 minCost: 4
node: 1 minCost: 4
node: 2 minCost: 5
node: 2 minCost: 6
node: 2 minCost: 6
node: 2 minCost: 6
node: 2 minCost: 6
node: 2 minCost: 6
node: 2 minCost: 6
node: 2 minCost: 6
node: 2 minCost: 6
node: 2 minCost: 6
node: 1 minCost: 7
node: 1 minCost: 7
node: 1 minCost: 8
node: 1 minCost: 8
node: 2 minCost: 9
node: 2 minCost: 9
node: 2 minCost: 9
node: 2 minCost: 9
node: 2 minCost: 10
node: 2 minCost: 10
node: 2 minCost: 10
node: 2 minCost: 10

Case 1: 5

*/
