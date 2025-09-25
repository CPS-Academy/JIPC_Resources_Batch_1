class Solution {
public:

    void dfs(int u, int par, int &cnt, vector<vector<pair<int, int>>> &adj) {
        for ( auto e : adj[u] ) {
            int v = e.first;
            int w = e.second;

            if(par != v) {
                cnt += w;
                dfs ( v, u, cnt, adj );
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj (n);

        for ( auto e : connections ) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        int cnt = 0;
        dfs(0, -1, cnt, adj);

        return cnt;
    }
};
