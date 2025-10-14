class Solution {
public:
    int n, m;
    
    void dfs(vector<vector<char> > & board, int x, int y){
        if(x<0 || y<0 || x>=n || y>= m)return;
        if(board[x][y] == 'X' || board[x][y] == '1')return;

        board[x][y] = '1';

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for(int i=0; i<4; i++){
            dfs(board, x+dx[i], y+dy[i]);
        }

    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        for(int i=0; i<n; i++){
            dfs(board, i, 0);
            dfs(board, i, m-1);
        }
        for(int i=0; i<m; i++){
            dfs(board, 0, i);
            dfs(board, n-1, i);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == '1')board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }

    }
};