class Solution {
public:

    void dfs (int x, int y, int n, int m, int color, vector<vector<int>>& image) {
        int prevColor = image[x][y];
        image[x][y] = color;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for ( int i = 0; i < 4; i++ ) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if( nx >= 0 && ny >= 0 && nx < n && ny < m && image[nx][ny] == prevColor ) {
                dfs ( nx, ny, n, m, color, image );
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        if(image[sr][sc] != color) {
            dfs ( sr, sc, n, m, color, image );
        }

        return image;
    }
};
