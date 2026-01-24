class Solution {
private:
    int MAX_CHARACTER_LIMIT = 26;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> letterCount_inputString_map;
        for(auto& str: strs) {
            vector<int> letterCount(MAX_CHARACTER_LIMIT, 0);
            for(auto& ch: str) {
                letterCount[ch - 'a']++;
            }
            string letterCountString = "";
            for(auto& count: letterCount) {
                letterCountString += to_string(count) + ",";
            }
            letterCount_inputString_map[letterCountString].push_back(str);
        }
        vector<vector<string>> groupAnagrams;
        for(auto& anagramGroups: letterCount_inputString_map) {
            groupAnagrams.push_back(anagramGroups.second);
        }
        return groupAnagrams;
    }
};
