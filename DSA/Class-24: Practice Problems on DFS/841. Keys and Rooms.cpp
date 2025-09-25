class Solution {
public:
    void dfs (int u, vector<bool> &vis, vector<vector<int>>& rooms) {
        vis[u] = 1;

        for ( auto v : rooms[u] ) {
            if ( !vis[v] ) {
                dfs(v, vis, rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, 0);
        dfs(0, vis, rooms);

        for ( int i = 0; i < n; i++ ) {
            if ( !vis[i] ) return false;
        }

        return true;
    }
};
