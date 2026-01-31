class Solution {
private:
    constexpr static int direction[5] = {0, 1, 0, -1, 0};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int height = heights.size(), weidth = heights[0].size();
        vector<vector<int>> minEffort(height, vector<int>(weidth, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        minEffort[0][0] = 0;
        minHeap.push({0, 0, 0}); // [min effort, row, col]
        while(!minHeap.empty()) {
            vector<int> u = minHeap.top(); minHeap.pop();
            int currentMinEffort = u[0];
            int row = u[1], col = u[2];
            if(minEffort[row][col] < currentMinEffort) {
                continue;
            }

            for(int dir = 1; dir <= 4; dir++) {
                int nextRow = row + direction[dir - 1];
                int nextCol = col + direction[dir];
                if(nextRow < 0 || height <= nextRow || nextCol < 0 || weidth <= nextCol) {
                    continue;
                }
                int effort = abs(heights[row][col] - heights[nextRow][nextCol]);
                if(max(currentMinEffort, effort) < minEffort[nextRow][nextCol]) {
                    minEffort[nextRow][nextCol] = max(currentMinEffort, effort);
                    minHeap.push({minEffort[nextRow][nextCol], nextRow, nextCol});
                }
            }
        }

        return minEffort[height - 1][weidth - 1];
    }
};
