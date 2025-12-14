class Solution {
private:
    int wallSize;
    vector<vector<int>> minAmount;
    int findMinCostOfPainting(int position, int remainingWallsToPaint, vector<int>& cost, vector<int>& time) {
        if(remainingWallsToPaint <= 0) {
            return 0;
        }
        if(position == wallSize) {
            if(remainingWallsToPaint > 0) return INT_MAX/2;
            return 0;
        }

        if(minAmount[position][remainingWallsToPaint] != -1) 
            return minAmount[position][remainingWallsToPaint];

        int paint = cost[position] + findMinCostOfPainting(position + 1, remainingWallsToPaint - 1 - time[position], cost, time);
        int dontPaint = findMinCostOfPainting(position + 1, remainingWallsToPaint, cost, time);

        return minAmount[position][remainingWallsToPaint] = min(paint, dontPaint);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        wallSize = cost.size();
        minAmount.assign(wallSize + 1, vector<int>(wallSize + 1, -1));
        return findMinCostOfPainting(0, wallSize, cost, time);
    }
};
