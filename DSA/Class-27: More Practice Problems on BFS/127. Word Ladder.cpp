class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> isInWordList;
        unordered_map<string, vector<string>> adjList;
        unordered_map<string, int> level;
        int len = wordList[0].size();

        wordList.push_back(beginWord);

        for ( auto u : wordList ) {
            isInWordList[u] = true;
        }

        for ( auto u : wordList ) {
            for ( int i = 0; i < len; i++ ) {
                for ( int j = 0; j < 26; j++ ) {
                    string v = u;
                    v[i] = j + 'a';

                    if (isInWordList[v]) {
                        adjList[u].push_back(v);
                        adjList[v].push_back(u);
                    }
                }
            }
        }

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 1;

        while ( !q.empty() ) {
            string u = q.front();
            q.pop();

            for ( auto v : adjList[u] ) {
                if ( level[v] == 0 ) {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }

        return level[endWord];
    }
};
