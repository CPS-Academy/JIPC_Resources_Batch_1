class Solution {
public:
    bool wordPattern(string pattern, string s) {    // T.C: O(|pattern| + |s|) S.C: O(|pattern| + |s|)
        unordered_map<string, int> stringToIndexMap;

        vector<string> wordList;
        stringstream ss(s);
        string word;
        while(ss >> word) {
            wordList.push_back(word);
        }
        if(wordList.size() != pattern.size()) {
            return false;
        }

        for(int i = 0; i < pattern.size(); i++) {
            string patternString = to_string(pattern[i]);
            if(!stringToIndexMap.count(patternString)) {
                stringToIndexMap[patternString] = i;
            }
            if(!stringToIndexMap.count(wordList[i])) {
                stringToIndexMap[ wordList[i] ] = i;
            }
            if(stringToIndexMap[patternString] != stringToIndexMap[ wordList[i] ]) {
                return false;
            }
        }
        return true;
    }
};

