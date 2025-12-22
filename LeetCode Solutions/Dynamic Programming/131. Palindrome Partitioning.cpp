class Solution {
private:
    vector<vector<string>> partitionedPalindromeList;
    vector<string> currentList;
    bool isPalindrome(string& s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if(s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    void findPalindromePartitions(int currentIndex, string& s) {
        if(currentIndex == s.size()) {
            partitionedPalindromeList.push_back(currentList);
        }
        string partitionString = "";
        for(int pos = currentIndex; pos < s.size(); pos++) {
            partitionString.push_back(s[pos]);
            if(isPalindrome(partitionString)) {
                currentList.push_back(partitionString);
                findPalindromePartitions(pos + 1, s);
                currentList.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        findPalindromePartitions(0, s);
        return partitionedPalindromeList;
    }
};
