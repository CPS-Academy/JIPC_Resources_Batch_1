class Solution {
private:
    const int INVALID = -1;
    vector<vector<int>> lcsLengthStore;
    string Text1, Text2;
    int findLCS(int i, int j) {
        if(i == Text1.size() || j == Text2.size()) {
            return 0;
        }
        int& currentLcs = lcsLengthStore[i][j];
        if(currentLcs != INVALID) {
            return currentLcs;
        }
        if(Text1[i] == Text2[j]) {
            currentLcs = 1 + findLCS(i + 1, j + 1);
        }
        else {
            currentLcs = max(findLCS(i + 1, j), findLCS(i, j + 1));
        }
        return currentLcs;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        lcsLengthStore.assign(text1.size(), vector<int>(text2.size(), INVALID));
        Text1 = text1, Text2 = text2;
        return findLCS(0, 0);
    }
};
