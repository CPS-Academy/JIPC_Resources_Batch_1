class Solution {
private:
    int INVALID = -1;
    vector<vector<int>> lcsStore;
    int findLcs(int i, int j, string& text1, string& text2) {
        if(i == text1.size() || j == text2.size()) { // base case
            return 0;
        }
        if(lcsStore[i][j] != INVALID) { // memorization
            return lcsStore[i][j];
        }
        // transition
        int& currentLcs = lcsStore[i][j];
        if(text1[i] == text2[j]) {
            currentLcs = 1 + findLcs(i + 1, j + 1, text1, text2);
        }
        else {
            currentLcs = max(findLcs(i + 1, j, text1, text2), findLcs(i, j + 1, text1, text2));
        }
        return currentLcs;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        lcsStore.assign(text1.size(), vector<int>(text2.size(), INVALID));
        return findLcs(0, 0, text1, text2);
    }
};
