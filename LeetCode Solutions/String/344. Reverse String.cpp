class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int L = 0, R = s.size() - 1; L < R; L++, R--) {
            char temp = s[L];
            s[L] = s[R];
            s[R] = temp;
        }
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int L = 0, R = s.size() - 1; L < R; L++, R--) {
            swap(s[L], s[R]);
        }
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};
