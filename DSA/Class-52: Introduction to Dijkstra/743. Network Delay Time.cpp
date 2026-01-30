class Solution {
private:
    vector<int> edges[102], costs[102];
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto& time: times) { // [fromNode, toNode, cost]
            edges[ time[0] ].push_back(time[1]);
            costs[ time[0] ].push_back(time[2]);
        }

        vector<int> minNetworkDelay(n + 1, INT_MAX);
        minNetworkDelay[k] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, k}); // [min cost, node]

        while(!minHeap.empty()) {
            vector<int> u = minHeap.top(); minHeap.pop();
            int timeToReachTheNode = u[0];
            int currentNode = u[1];

            if(minNetworkDelay[currentNode] < timeToReachTheNode) {
                continue;
            }

            for(int i = 0; i < edges[currentNode].size(); i++) {
                int nextNode = edges[currentNode][i];
                int cost = costs[currentNode][i];
                if(timeToReachTheNode + cost < minNetworkDelay[nextNode]) {
                    minNetworkDelay[nextNode] = timeToReachTheNode + cost;
                    minHeap.push({timeToReachTheNode + cost, nextNode});
                }
            }
        }

        int minTimeForAllNode = 0;
        for(int node = 1; node <= n; node++) {
            minTimeForAllNode = max(minTimeForAllNode, minNetworkDelay[node]);
        }

        return (minTimeForAllNode == INT_MAX) ? -1 : minTimeForAllNode;
    }
};
