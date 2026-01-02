class Solution {
private:
    vector<vector<int>> storeIsPalindrome;
    string S;
    int isPalindrome(int L, int R) {
        if(L >= R) {
            return 1;
        }
        if(storeIsPalindrome[L][R] != -1) {
            return storeIsPalindrome[L][R];
        }

        cout << "count" << '\n';

        if(S[L] == S[R]) {
            return storeIsPalindrome[L][R] = isPalindrome(L + 1, R - 1);
        }
        else {
            return storeIsPalindrome[L][R] = 0;
        }
    }
public:
    string longestPalindrome(string s) {

        for(int L = 0; L < s.size(); L++) { // O(N)
            for(int R = L; R < s.size(); R++) { // O(N)
                isPalindrome(L, R)
            }
        }

        storeIsPalindrome.assign(s.size(), vector<int>(s.size(), -1));
        S = s;
        string longestPalindrome = "";
        for(int L = 0; L < s.size(); L++) { // O(N)
            for(int R = L; R < s.size(); R++) { // O(N)
                if(isPalindrome(L, R) && R - L + 1 >= longestPalindrome.size()) { // O(1)
                    longestPalindrome = s.substr(L, R - L + 1);
                }
            }
        }
        return longestPalindrome;
    }
};

/*
    aaaa
    0123

    0,0
    1,1 -> 0,2
    2,2 -> 1, 3
    3,3

*/
