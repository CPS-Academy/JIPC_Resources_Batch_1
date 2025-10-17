// BFS Solution
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int> > dist = mat;

        queue<pair<int, int> > q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    mat[i][j] = -1;
                }
            }
        }

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int x = node.first;
            int y = node.second;

            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};

            for(int i=0; i<4; i++){
                int a = x + dx[i];
                int b = y + dy[i];

                if(a >=0 && a<n && b>=0 && b<m && mat[a][b] != -1){
                    dist[a][b] = dist[x][y] + 1;
                    mat[a][b] = -1;
                    q.push({a, b});
                }

            }
        }

        return dist;

        
    }
};



// DP Solution 

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& dp) {
        
        int n = dp.size();
        int m = dp[0].size();


        // 0, 0, to n-1, m-1;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(dp[row][col]==0){
                    continue;
                }
                dp[row][col] = n * m;

                if(row > 0) dp[row][col] = min(dp[row][col], dp[row-1][col] + 1);
                if(col > 0) dp[row][col] = min(dp[row][col], dp[row][col-1] + 1); 
            }
        }

        // n-1, m-1 to 0, 0
        for(int row = n-1; row >=0; row--){
            for(int col = m-1; col >=0; col--){
                if(dp[row][col]==0){
                    continue;
                }

                if(row < n - 1)
                    dp[row][col] = min(dp[row][col], 1 + dp[row + 1][col]);
                
                if(col < m - 1)
                    dp[row][col] = min(dp[row][col], 1 + dp[row][col + 1]);

            }
        }

        return dp;
    }
};