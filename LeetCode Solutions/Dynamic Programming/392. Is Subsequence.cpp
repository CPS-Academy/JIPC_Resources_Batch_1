class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pointerOfS = 0;
        for(int pointerOfT = 0; pointerOfT < t.size(); pointerOfT++) {
            if(s[pointerOfS] == t[pointerOfT]) pointerOfS++;
        }
        return(pointerOfS == s.size());
    }
};
