class Solution {
private:
    vector<vector<int>> ways;
    int ncr(int n, int r) {
        if(n == r || n == 0 || r == 0) return 1;
        if(ways[n][r] != -1) return ways[n][r];
        return ways[n][r] = ncr(n - 1, r - 1) + ncr(n - 1, r);
    }
public:
    vector<int> getRow(int rowIndex) {
        ways.assign(rowIndex + 1, vector<int>(rowIndex + 1, -1));
        vector<int> result;
        for(int i = 0; i <= rowIndex; i++){
            int currentResult = ncr(rowIndex, i);
            result.push_back(currentResult);
        }
        return result;
    }
};
