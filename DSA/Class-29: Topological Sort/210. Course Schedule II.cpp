class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for ( auto edge : prerequisites ) {
            int u = edge[1]; // 0, 1 -> 1 to 0
            int v = edge[0];
           
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        for ( int i = 0; i < numCourses; i++ ) {
            if ( inDegree[i] == 0 ) {
                q.push(i);
            }
        }

        vector<int> ans;

        while ( !q.empty() ) {
            int u = q.front();
            q.pop();

            ans.push_back(u);

            for ( auto v : adj[u] ) {
                inDegree[v]--;
                if ( inDegree[v] == 0 ) {
                    q.push(v);
                }
            }
        }

        if(ans.size() != numCourses) return {};
        return ans;
    }
};

