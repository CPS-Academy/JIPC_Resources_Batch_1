class Solution {
public:
    bool isAnagram(string s, string t) { // T.C: O(N), S.C: O(1)
        if(s.size() != t.size()) {
            return false;
        }

        vector<int> alphabetFreq(26, 0);
        for(int i = 0; i < s.size(); i++) {
            alphabetFreq[ s[i] - 'a' ]++;
            alphabetFreq[ t[i] - 'a' ]--;
        }

        for(int i = 0; i < 26; i++) {
            if(alphabetFreq[i] != 0) {
                return false;
            }
        }
        return true;

    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }

        vector<int> alphabetFreq_s(26, 0);
        vector<int> alphabetFreq_t(26, 0);
        for(int i = 0; i < s.size(); i++) {
            alphabetFreq_s[ s[i] - 'a' ]++;
            alphabetFreq_t[ t[i] - 'a' ]++;
        }

        for(int i = 0; i < 26; i++) {
            if(alphabetFreq_s[i] != alphabetFreq_t[i]) {
                return false;
            }
        }
        return true;

    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
