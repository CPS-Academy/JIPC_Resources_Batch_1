class Solution {
public:

    void dfs(int x, int y, vector<vector<int> > &grid){
        grid[x][y] = 2;

        int n = grid.size();

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for(int i =0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >=0 && nx < n && ny < n && grid[nx][ny] == 1){
                dfs(nx, ny, grid);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {

        int n = grid.size();

        for(int i=0; i<n; i++){
            bool f = 0;
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid);
                    f = 1;
                    break;
                }
            }
            if(f)break;
        }


        queue<vector<int> > q; // x, y, len

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                }
            }
        }

        cout<<q.size()<<endl;

        int ans = n * n;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int x = node[0];
            int y = node[1];
            int len = node[2];

            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >=0 && nx < n && ny < n && grid[nx][ny] !=2){
                    q.push({nx, ny, len + 1});
                    if(grid[nx][ny] == 1){
                        ans = min(ans, len);
                    }
                    grid[nx][ny] = 2;
                }
            }
        }

        return ans;
        
    }
};