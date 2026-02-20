class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        int lastbit;
        // time O(logn), space O(1)
        while(n > 0){
            lastbit = (n - 1) % 26; // get last bit/digit
            n = (n - 1) / 26;  // delete last bit/digit
            // cout << lastbit << endl;
            ans += (lastbit + 'A');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
