class Solution {
private:
    const int INVALID = -1;
    int direction[5] = {0, 1, 0, -1, 0};
    int height, weidth;
    vector<vector<int>> lip_store;
    vector<vector<int>> Matrix;

    bool isInsideMatrix(int row, int col) {
        return (0 <= row && row < height && 0 <= col && col < weidth);
    }
    int findLIP(int row, int col) {
        int& lipValue = lip_store[row][col];
        if(lipValue != INVALID) {
            return lipValue;
        }

        lipValue = 0;
        for(int dir = 1; dir <= 4; dir++) {
            int newRow = row + direction[dir - 1]; // 0 1 -1 0
            int newCol = col + direction[dir];     // 1 0 0 -1
            // cout << newRow << " " << newCol << '\n';

            if(isInsideMatrix(newRow, newCol) && Matrix[row][col] < Matrix[newRow][newCol]) {
                int value = findLIP(newRow, newCol);
                lipValue = max(lipValue, value);
            }
        }
        return ++lipValue;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        height = matrix.size(), weidth = matrix[0].size();
        lip_store.assign(height, vector<int>(weidth, INVALID));
        Matrix = matrix;
        
        int maxLIP = 0;
        for(int row = 0; row < height; row++) {
            for(int col = 0; col < weidth; col++) {
                maxLIP = max(maxLIP, findLIP(row, col));
            }
        }
        return maxLIP;
    }
};
