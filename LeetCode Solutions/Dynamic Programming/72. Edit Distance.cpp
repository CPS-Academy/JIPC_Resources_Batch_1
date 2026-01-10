class Solution {
private:
    const int INVALID = -1;
    int word1_length, word2_length;
    string Word1, Word2;
    vector<vector<int>> storeMinOperations;

    int findMinOperations(int word1_index, int word2_index) {
        if(word1_index == word1_length) {
            return word2_length - word2_index;
        }
        if(word2_index == word2_length) {
            return word1_length - word1_index;
        }

        int& minOperations = storeMinOperations[word1_index][word2_index];
        if(minOperations != INVALID) {
            return minOperations;
        }

        if(Word1[word1_index] == Word2[word2_index]) {
            minOperations = findMinOperations(word1_index + 1, word2_index + 1);
        }
        else{
            int minCostWithInsert = findMinOperations(word1_index, word2_index + 1);
            int minCostWithReplace = findMinOperations(word1_index + 1, word2_index + 1);
            int minCostWithDelete = findMinOperations(word1_index + 1, word2_index);
            minOperations = 1 + min({minCostWithInsert, minCostWithReplace, minCostWithDelete});
        }
        return minOperations;
    }
public:
    int minDistance(string word1, string word2) {
        Word1 = word1;
        Word2 = word2;
        word1_length = Word1.size();
        word2_length = Word2.size();
        storeMinOperations.assign(word1_length, vector<int>(word2_length, INVALID));
        return findMinOperations(0, 0);
    }
};
