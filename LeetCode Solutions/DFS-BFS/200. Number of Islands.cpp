DFS solution:

class Solution {
public:
    void dfs (int x, int y, int n, int m, vector<vector<char>>& grid) {
        grid[x][y] = '#';

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for ( int i = 0; i < 4; i++ ) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ( nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '1' ) {
                dfs ( nx, ny, n, m, grid );
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                if ( grid[i][j] == '1' ) {
                    ans++;
                    dfs(i, j, n, m, grid);
                }
            }
        }

        return ans;
    }
};








BFS Solution:


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int ans = 0;

        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                if ( grid[i][j] == '1' ) {
                    ans++;
                    queue<pair<int,int>> q;
                    q.push({i, j});

                    while ( !q.empty() ) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for ( int k = 0; k < 4; k++ ) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if ( nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '1' ) {
                                grid[nx][ny] = '#';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};
