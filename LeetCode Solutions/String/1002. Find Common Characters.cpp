class Solution {
private:
    const static int CHARACTER_LIMIT = 26;
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> commonLetterCount(CHARACTER_LIMIT, INT_MAX);
        for(auto& word: words) {
            vector<int> letterFrequency(CHARACTER_LIMIT, 0);
            for(char& ch: word) {
                letterFrequency[ ch - 'a' ]++;
            }
            for(int letterPosition = 0; letterPosition < CHARACTER_LIMIT; letterPosition++) {
                commonLetterCount[letterPosition] = min(commonLetterCount[letterPosition], 
                    letterFrequency[letterPosition]);
            }
        }

        vector<string> commonCharacters;
        for(int letterPosition = 0; letterPosition < CHARACTER_LIMIT; letterPosition++) {
            while(commonLetterCount[letterPosition]--) {
                char ch = 'a' + letterPosition;
                commonCharacters.push_back(string(1, ch));
            }
        }

        return commonCharacters;
    }
};
