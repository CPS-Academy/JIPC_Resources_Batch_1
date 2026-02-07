class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mappingFromS, mappingFromT;
        for(int i = 0; i < s.size(); i++) {
            mappingFromS[ s[i] ] = t[i];
            mappingFromT[ t[i] ] = s[i];
        }
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != mappingFromT[ t[i] ] || t[i] != mappingFromS[ s[i] ]) {
                return false;
            }
        }
        return true;
    }
};
