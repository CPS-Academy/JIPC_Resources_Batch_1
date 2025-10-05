// DFS:

class Solution {
public:
    void dfs(int u, int clr, bool &isBipartite, vector<int> &color,  vector<vector<int>>& adj) {
        color[u] = clr;

        for ( auto v : adj[u] ) {
            if ( color[v] == 0 ) {
                dfs ( v, (clr == 1) ? 2 : 1, isBipartite, color, adj );
            }
            else if ( color[v] == color[u] ) {
                isBipartite = false;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        bool isBipartite = true;

        for ( int i = 0; i < n; i++ ) {
            if ( color[i] == 0 ) {
                dfs ( i, 1, isBipartite, color, graph );
            }
        }

        return isBipartite;
    }
};

// BFS:

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        for ( int i = 0; i < n; i++ ) {
            if ( color[i] == 0 ) {
                queue<int> q;
                q.push(i);
                color[i] = 1;

                while ( !q.empty() ) {
                    int u = q.front();
                    q.pop();

                    int clr = ( color[u] == 1 ) ? 2 : 1;

                    for ( auto v : graph[u] ) {
                        if ( color[v] == 0 ) {
                            q.push(v);
                            color[v] = clr;
                        }
                        else if ( color[v] == color[u] ) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

// Cycle finding and Printing:

vector<int> adj[100];
bool visited[100];
bool cycle = false;
int parent[100];
int lastNodeCycle = -1;
int cycleStart = -1;
int cycleEnd = -1;

void dfs(int u) // u = 4, parent = 3
{
    visited[u] = true;
    for ( auto v : adj[u]  ) {// v = 1
        if ( !visited[v] ) {
            parent[v] = u;
            dfs(v);
        }
        else if ( cycleStart == -1 && v != parent[u] ) {
            cycleStart = u;
            cycleEnd = v;
        }
    }
}

int main()
{
    optimize();

    int n, m;
    cin >> n >> m;
    mem ( parent, -1 );

    for ( int i = 1; i <= m; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }

    dfs (1);
    if ( cycleStart != -1 ) {
        cout << "Cycle Exists" << endl;

        int u = cycleStart;
        while ( u != cycleEnd ) {
            cout << u << " ";
            u = parent[u];
        }

        cout << cycleEnd << endl;
    }
    else {
        cout << "Cycle does not exist" << endl;
    }

    return 0;
}

