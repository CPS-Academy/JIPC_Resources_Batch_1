class Solution {
private:
    static bool compare(string& a, string& b) {
        return a.size() < b.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare); // O(NlogN)
        unordered_map<string, int> maxLengthOfSequanceEndAtTheString;
        int longestChainLength = 1;

        for(string& word: words) { // O(N)
            maxLengthOfSequanceEndAtTheString[word] = 1;
            for(int removeIndex = 0; removeIndex < word.size(); removeIndex++) { // O(L)
                string firstPart = word.substr(0, removeIndex); // O(L)
                string lastPart = word.substr(removeIndex + 1); // O(L)
                string currentWord = firstPart + lastPart;
                if(maxLengthOfSequanceEndAtTheString.count(currentWord)) { // O(1)
                    maxLengthOfSequanceEndAtTheString[word] = 
                        max(maxLengthOfSequanceEndAtTheString[word], 1 + maxLengthOfSequanceEndAtTheString[currentWord]); // O(1)
                }
            }
            longestChainLength = max(longestChainLength, maxLengthOfSequanceEndAtTheString[word]);
        }

        return longestChainLength;
    }
};
