class Solution {
private:
    int height;
    int weidth;
    bool traverseDiagonally(int row, int col, vector<vector<int>>& matrix) {
        int diagonalValue = matrix[row][col];
        for(int newRow = row, newCol = col; newRow < height && newCol < weidth; newRow++, newCol++) {
            if(matrix[newRow][newCol] != diagonalValue) {
                return false;
            }
        }
        return true;
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        height = matrix.size();
        weidth = matrix[0].size();
        int isToeplitz = true;
        for(int col = 0; col < weidth; col++) {
            isToeplitz &= traverseDiagonally(0, col, matrix);
        }
        for(int row = 1; row < height; row++) {
            isToeplitz &= traverseDiagonally(row, 0, matrix);
        }
        return isToeplitz;
    }
};
