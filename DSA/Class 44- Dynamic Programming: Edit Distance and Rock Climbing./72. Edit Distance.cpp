class Solution {
private:
    const int INVALID = -1;

    int word1Length, word2Length;
    string Word1, Word2;
    vector<vector<int>> storeMinDistance;
    
    int findMinDistance(int word1_index, int word2_index) {
        // Base Case
        if(word1_index == word1Length) {
            return word2Length - word2_index;
        }
        if(word2_index == word2Length) {
            return word1Length - word1_index;
        }

        // Memorization
        int& minDistance = storeMinDistance[word1_index][word2_index];
        if(minDistance != INVALID) {
            return minDistance;
        }

        // Transitions
        if(Word1[word1_index] == Word2[word2_index]) {
            return minDistance = findMinDistance(word1_index + 1, word2_index + 1);

            // current_operation[word1_index][word2_index] = [0]
        }
        else {
            int minCostWithInsert = 1 + findMinDistance(word1_index, word2_index + 1);
            int minCostWithReplace = 1 + findMinDistance(word1_index + 1, word2_index + 1);
            int minCostWithDelete = 1 + findMinDistance(word1_index + 1, word2_index);

            // current_operation[word1_index][word2_index] = [1, 2, 3]

            return minDistance = min({minCostWithInsert, minCostWithReplace, minCostWithDelete});
        }
    }
public:
    int minDistance(string word1, string word2) {
        storeMinDistance.assign(word1.size() + 1, vector<int>(word2.size() + 1, INVALID));
        Word1 = word1, Word2 = word2;
        word1Length = Word1.size(), word2Length = Word2.size();
        return findMinDistance(0, 0);
    }
};
