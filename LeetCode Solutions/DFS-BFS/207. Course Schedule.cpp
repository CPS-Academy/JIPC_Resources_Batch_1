//Topological Solution 

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> indeg(numCourses, 0);
        vector<vector<int> > graph(numCourses);

        for(auto cur: prerequisites){
            int a = cur[0];
            int b = cur[1];
            indeg[a]++;
            graph[b].push_back(a);
        }

        queue<int> q;
    
        for(int i=0; i<numCourses; i++){
            if(indeg[i]==0)q.push(i);
        }

        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            cnt++;
            q.pop();
            for(auto v : graph[node]){
                indeg[v]--;
                if(indeg[v]==0)
                    q.push(v);
            }
        }

        if(cnt == numCourses)return true;
        return false;
    }
};

// Directed Graph Cycle Solution


class Solution {
public:

    vector<vector<int> > graph;
    vector<int> vis;

    bool isCycle = false;

    void dfs(int node){
        vis[node] = 1;

        for(auto child: graph[node]){
            if(vis[child]==1){
                isCycle = true;
                continue;
            }
            if(vis[child]==2)continue;
            dfs(child);
        }

        vis[node] = 2;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        graph.resize(numCourses);
        vis.resize(numCourses, 0);
        
        for(auto ii: prerequisites){
            int a = ii[0];
            int b = ii[1];

            graph[b].push_back(a);
        }

        for(int i = 0; i < numCourses; i++){
            if(vis[i])continue;
            dfs(i);
        }

        return !isCycle;


    }
};