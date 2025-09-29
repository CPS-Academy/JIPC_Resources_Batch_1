class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        int n = maze.size();
        int m = maze[0].size();

        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0 });
        maze[entrance[0]][entrance[1]] = '+';
        int ans = n * m;

        while ( !q.empty() ) {
            vector<int> curr = q.front();
            q.pop();

            int x = curr[0];
            int y = curr[1];
            int currLevel = curr[2];

            for ( int i = 0; i < 4; i++ ) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if ( nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == '.') {
                    int nextLevel = currLevel + 1;
                    maze[nx][ny] = '+';

                    if ( nx == 0 || ny == 0 || nx == n-1 || ny == m-1 ) {
                        ans = min ( ans, nextLevel );
                    }

                    q.push({nx, ny, nextLevel});
                }
            }
        }

        if ( ans == (n*m) ) ans = -1;
        return ans;
    }
};
