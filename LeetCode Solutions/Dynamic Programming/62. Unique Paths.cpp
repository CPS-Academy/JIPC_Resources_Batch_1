class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n > m) swap(n, m);
        vector<int> ways(n, 1);
        for(int row = 1; row < m; row++) {
            for(int col = 1; col < n; col++) {
                ways[col] += ways[col - 1];
            }
        }
        return ways[n - 1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ways(m + 1, vector<int>(n + 1, 0));
        ways[1][1] = 1;
        for(int row = 1; row <= m; row++) {
            for(int col = 1; col <= n; col++) {
                if(row != 1 || col != 1) {
                    ways[row][col] = ways[row - 1][col] + ways[row][col - 1];
                }
            }
        }
        return ways[m][n];
    }
};
