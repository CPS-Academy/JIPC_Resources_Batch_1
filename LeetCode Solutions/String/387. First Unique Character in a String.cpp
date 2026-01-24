class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> character_count;
        for(int i = 0; i < s.size(); i++) {
            character_count[ s[i] - 'a' ]++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(character_count[ s[i] - 'a' ] == 1) {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> character_count;
        for(int i = 0; i < s.size(); i++) {
            character_count[ s[i] - 'a' ]++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(character_count[ s[i] - 'a' ] == 1) {
                return i;
            }
        }
        return -1;
    }
};
