class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indeg(numCourses, 0);
        vector<vector<int> > graph(numCourses);

        for(auto cur: prerequisites){
            indeg[cur[0]]++;
            graph[cur[1]].push_back(cur[0]);
        }

        queue<int> q;

        for(int i = 0; i<numCourses; i++){
            if(indeg[i]==0)q.push(i);
        }

        vector<int> res;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            res.push_back(node);

            for(auto v: graph[node]){
                indeg[v]--;
                if(indeg[v] == 0)
                    q.push(v);
            }
        }

        if(res.size() < numCourses) return {};
        return res;
        
    }
};