class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dx[] = {+1, -1, 0, 0, -1, +1, -1, +1};
        int dy[] = {0, 0, -1, +1, +1, -1, -1, +1};

        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        if(n == 1) return 1;

        queue<vector<int>> q;
        q.push({0, 0, 0});
        grid[0][0] = 1;

        while ( !q.empty() ) {
            vector<int> cur = q.front();
            q.pop();

            int x = cur[0];
            int y = cur[1];
            int curLevel = cur[2];

            for ( int i = 0; i < 8; i++ ) {
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                if ( nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0 ) {
                    int nextLevel = curLevel + 1;
                    grid[nx][ny] = 1;

                    q.push({ nx, ny, nextLevel });
                    if ( nx == n-1 && ny == n-1 ) return nextLevel + 1;
                }
            }
        }

        return -1;
    }
};

