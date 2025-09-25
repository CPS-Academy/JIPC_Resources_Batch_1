class Solution {
public:

    void dfs ( int u, int n, bool &done, vector<bool> &vis, vector<int>& arr ) {
        vis[u] = 1;
        if ( arr[u] == 0 ) done = true;
        if(done) return;

        int v = u + arr[u];
        if ( v < n && !vis[v] ) {
            dfs ( v, n, done, vis, arr );
        }

        v = u - arr[u];
        if ( v >= 0 && !vis[v] ) {
            dfs ( v, n, done, vis, arr );
        }

        return;
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, 0);
        bool done = false;
        dfs ( start, n, done, vis, arr );

        return done;
    }
};
