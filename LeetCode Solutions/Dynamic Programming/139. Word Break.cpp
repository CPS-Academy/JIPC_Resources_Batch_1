class Solution {
private:
    const int INVALID = -1;
    const static int MAX_LIMIT = 26;
    vector<int> isPossibleToMake;

    class TrieNode {
        public:
        bool hasEnd = false;
        TrieNode* next[MAX_LIMIT] = {};
    };

    TrieNode* root;
    void buildTrie(vector<string>& wordDict) {
        root = new TrieNode();
        for(auto& word: wordDict) {
            auto currNode = root;
            for(char& ch: word) {
                if(currNode -> next[ch - 'a'] == NULL) {
                    currNode -> next[ch - 'a'] = new TrieNode();
                }
                currNode = currNode -> next[ch - 'a'];
            }
            currNode -> hasEnd = true;
        }
    }

    bool isPossible(int currentIndex, string s, vector<string>& wordDict) {
        if(currentIndex == s.size()) { // base case
            return true;
        }
        if(isPossibleToMake[currentIndex] != INVALID) { // memorization
            return isPossibleToMake[currentIndex];
        }

        auto currNode = root;
        bool isPossibleFromIndex = false;
        for(int i = currentIndex; i < s.size(); i++) {
            if(currNode -> next[ s[i] - 'a' ] == NULL) {
                break;
            }
            currNode = currNode -> next[ s[i] - 'a' ];
            if(currNode -> hasEnd) {
                isPossibleFromIndex |= isPossible(i + 1, s, wordDict);
            }
        }

        return isPossibleToMake[currentIndex] = isPossibleFromIndex;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        buildTrie(wordDict);
        isPossibleToMake.assign(s.size(), INVALID);
        return isPossible(0, s, wordDict);
    }
};


class Solution {
private:
    int INVALID = -1;

    vector<int> isPossibleToMake;

    bool isPossible(int currentIndex, string s, vector<string>& wordDict) {
        if(currentIndex == s.size()) { // base case
            return true;
        }
        if(isPossibleToMake[currentIndex] != INVALID) { // memorization
            return isPossibleToMake[currentIndex];
        }

        bool isPossibleFromIndex = false;
        for(auto& word: wordDict) { // recursive transitions
            if(currentIndex + word.size() <= s.size() && word == s.substr(currentIndex, word.size())) {
                isPossibleFromIndex |= isPossible(currentIndex + word.size(), s, wordDict);
            }
        }

        return isPossibleToMake[currentIndex] = isPossibleFromIndex;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        isPossibleToMake.assign(s.size(), INVALID);
        return isPossible(0, s, wordDict);
    }
};
