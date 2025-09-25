BFS with Grid:


int main()
{
    optimize();

    vector<vector<char>> grid = {
        {'#', '.', '.', '#', '#'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#'},
        {'#', '#', '.', '.', '.'}
    };

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> level(n, vector<int>(m, -1));
    pair<int,int> s = {2, 2};

    queue<pair<int,int>> q;
    q.push(s);
    level[s.first][s.second] = 0;

    while ( !q.empty() ) {
        pair<int,int> u = q.front();
        q.pop();

        int x = u.first;
        int y = u.second;

        for(int i = 0; i < 4; i++) { // 2, 1
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 1, 3
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && level[nx][ny] == -1) {
                level[nx][ny] = level[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }


    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < m; j++ ) {
            cout << level[i][j] << " ";
        }
        cout << endl;
    }
    


    return 0;
}



BFS on Nodes and Edges:



vector<int> adj[100];

int main()
{
    optimize();

    int n, m;
    cin >> n >> m;

    for ( int i = 1; i <= m; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }

    vector<int> level(n+1, -1);
    queue<int> q;
    q.push(1);
    level[1] = 0;

    while( !q.empty() ) {
        int u = q.front();
        q.pop();

        for ( auto v : adj[u] ) {
            if ( level[v] == -1 ) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    
    for ( int i = 1; i <= n; i++ ) {
        cout << i << " : " << level[i] << endl;
    }



    return 0;
}

/*

7 8
1 2
1 4
2 3
3 5
5 6
6 7
2 7
4 5

*/

























