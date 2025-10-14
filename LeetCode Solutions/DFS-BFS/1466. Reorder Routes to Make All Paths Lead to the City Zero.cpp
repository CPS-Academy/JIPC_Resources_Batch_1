class Solution {
public:

    vector<vector<pair<int, int> > > graph;
    vector<int> vis;
    int cost = 0;

    void dfs(int node){
        vis[node] = 1;
        
        for(auto child:graph[node]){
            if(vis[child.first])continue;
            cost += child.second;
            dfs(child.first);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        vis.resize(n+1, 0);

        for(auto ii:connections){
            int u = ii[0];
            int v = ii[1];
            // u -> v | 1 (reverse)
            // v -> u | 0 (reverse)
            graph[u].push_back({v, 1});
            graph[v].push_back({u, 0});
        }
        dfs(0);
        return cost;
    }
};