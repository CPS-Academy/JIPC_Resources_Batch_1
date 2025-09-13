class Solution {
public:

    void dfs (int u, vector<bool> &isVisited, int n, vector<vector<int>>& isConnected) {
        isVisited[u] = 1;

        for ( int v = 0; v < n; v++ ) {
            if ( isConnected[u][v] == 1 && isVisited[v] == 0 ) {
                dfs (v, isVisited, n, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> isVisited (n, 0);
       
        int ans = 0;
        for ( int i = 0; i < n; i++ ) {
            if ( isVisited[i] == 0 ) {
                ans++;
                dfs ( i, isVisited, n, isConnected );
            }
        }

        return ans;
    }
};
