class Solution {
public:

    vector<vector<int> > graph;
    vector<int> vis;

    void dfs(int node){
        vis[node] = 1;
        for(int v : graph[node]){
            if(vis[v])continue;
            dfs(v);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        graph.resize(n);
        vis.resize(n, 0);

        for(int a = 0; a < n; a++){
            for(int b : rooms[a]){
                graph[a].push_back(b);
            }
        }

        dfs(0);

        bool res = true;

        for(int i=0; i<n; i++){
            if(vis[i] == 0) res = false;
        }

        return res;
    }
};