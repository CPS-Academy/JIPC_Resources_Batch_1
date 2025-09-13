class Solution {
public:
    void dfs (int x, int y, int n, int m, vector<vector<char>>& grid) {
        grid[x][y] = '#';

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for ( int i = 0; i < 4; i++ ) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ( nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '1') {
                dfs ( nx, ny, n, m, grid );
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for ( int x = 0; x < n; x++ ) {
            for ( int y = 0; y < m; y++ ) {
                if ( grid[x][y] == '1' ) {
                    ans++;
                    dfs ( x, y, n, m, grid );
                }
            }
        }

        return ans;
    }
};
