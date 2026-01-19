class Solution {
private:
    int length;
    void performSwaps(int r, int c, vector<vector<int>>& matrix) {
        int temp = matrix[r][c];
        swap(temp, matrix[c][length - 1 - r]);
        swap(temp, matrix[length - r - 1][length - c - 1]);
        swap(temp, matrix[length - 1 - c][r]);
        matrix[r][c] = temp;
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        length = matrix.size();
        int rowLimit = length / 2;
        int colLimit = (length + 1) / 2;
        for (int row = 0; row < rowLimit; row++) {
            for (int col = 0; col < colLimit; col++) {
                performSwaps(row, col, matrix);
            }
        }
    }
};
