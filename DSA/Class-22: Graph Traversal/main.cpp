#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int n, int m, vector<vector<bool>>& isVisited, vector<vector<int>>& grid)
{
    isVisited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];  // x = 0, nx = 0
        int ny = y + dy[i];  // y = 0, ny = 1

        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1 && !isVisited[nx][ny])
        {
            dfs(nx, ny, n, m, isVisited, grid);
        }
    }
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 1}, {0, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 0, 1}};

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> isVisited(n, vector<bool>(m, 0));

    dfs(0, 0, n, m, isVisited, grid);

    return 0;
}

vector<int> adj[100];

void dfs(int u, vector<bool>& isVisited)
{
    isVisited[u] = true;

    for (auto v : adj[u])
    {
        if (!isVisited[v])
        {
            dfs(v, isVisited);
        }
    }
}
