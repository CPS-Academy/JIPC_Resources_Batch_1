class Solution {
private:
    int len_s, len_p;
    string S, P;
    unordered_map<int, bool> dp;
    bool findIsMatched(int str_index, int pattern_index) {
        int hashKey = str_index*10000 + pattern_index;
        if(dp.count(hashKey)) {
            return dp[hashKey];
        }

        bool& storeValue = dp[hashKey];
        if(pattern_index == len_p) {
            storeValue = (str_index == len_s);
        }
        else if(str_index == len_s) {
            storeValue = (pattern_index + 1 == len_p && P[pattern_index] == '*');
        }
        else if(S[str_index] == P[pattern_index] || P[pattern_index] == '?') {
            storeValue = findIsMatched(str_index + 1, pattern_index + 1);
        }
        else if(P[pattern_index] == '*') {
            storeValue = findIsMatched(str_index + 1, pattern_index) || findIsMatched(str_index, pattern_index + 1);
        }
        else{
            storeValue = false;
        }
        return storeValue;

    }
public:
    bool isMatch(string s, string p) {
        string removedDuplicateP = "";
        for(auto& ch: p) {
            if(removedDuplicateP.empty() || ch != '*') {
                removedDuplicateP.push_back(ch);
            }
            else if(removedDuplicateP.back() != '*') {
                removedDuplicateP.push_back(ch);
            }
        }

        len_s = s.size();
        len_p = removedDuplicateP.size();
        S = s, P = removedDuplicateP;
        return findIsMatched(0, 0);
    }
};
