class Solution {
public:
    int n;

    void dfs(vector<vector<int>> & isConnected, int node){
        isConnected[node][node] = 0;

        for(int i = 0; i<n; i++){
            if(isConnected[i][i] == 0)continue;
            if(isConnected[node][i])
                dfs(isConnected, i);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        int result = 0;
        for(int i=0; i<n; i++){
            if(isConnected[i][i] == 1){
                dfs(isConnected, i);
                result++;
            }
        }
        return result;
    }
};