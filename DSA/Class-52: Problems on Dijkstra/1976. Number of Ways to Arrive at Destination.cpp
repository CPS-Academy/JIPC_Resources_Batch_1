class Solution {
private:
    const static int MOD = 1000000007;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int> edges[201];
        vector<int> costs[201];
        for(auto& road: roads) {
            edges[ road[0] ].push_back(road[1]);
            costs[ road[0] ].push_back(road[2]);
            edges[ road[1] ].push_back(road[0]);
            costs[ road[1] ].push_back(road[2]);
        }

        vector<long long> minDistance(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        minDistance[0] = 0;
        ways[0] = 1;

        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            vector<long long> u = pq.top(); pq.pop();
            long long currentDistance = u[0];
            long long currentNode = u[1];

            if(minDistance[currentNode] < currentDistance) {
                continue;
            }

            for(int i = 0; i < edges[currentNode].size(); i++) {
                long long nextNode = edges[currentNode][i];
                long long cost = costs[currentNode][i];
                if(currentDistance + cost < minDistance[nextNode]) {
                    minDistance[nextNode] = currentDistance + cost;
                    ways[nextNode] = ways[currentNode];
                    pq.push({minDistance[nextNode], nextNode});
                }
                else if(currentDistance + cost == minDistance[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[currentNode]) %MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
