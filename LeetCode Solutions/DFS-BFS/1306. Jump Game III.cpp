// BFS Solution

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        vector<int> vis(n, 0);

        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            vis[node] = 1;
            q.pop();

            if(arr[node] == 0){
                return true;
            }
            
            if(node + arr[node] < n && vis[node + arr[node]] == 0){
                q.push(node + arr[node]);
            }
            if(node - arr[node] >= 0 && vis[node - arr[node]] == 0){
                q.push(node - arr[node]);
            }

        }

        return false;
        
    }
};


// DFS Solution

class Solution {
public:
    int n, res = 0;

    vector<int> vis;

    void dfs(vector<int> &arr, int node){
        vis[node] = 1;
        if(arr[node] == 0)res = 1;

        int a = node + arr[node];
        int b = node - arr[node];

        if( a < n && !vis[a]){
            dfs(arr, a);
        }
        if( b >= 0 && !vis[b]){
            dfs(arr, b);
        }
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vis.resize(n, 0);


        dfs(arr, start);

        return res;
    }
};