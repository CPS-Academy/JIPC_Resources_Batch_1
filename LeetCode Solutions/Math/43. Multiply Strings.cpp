class Solution {
public:
    string multiply(string& a, string& b) {
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());


        vector<int> v(a.size() + b.size(), 0);


        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < b.size(); j++){
                // O(n * m) time
                // O(n + m) space
                v[i + j] += (a[i] - '0') * (b[j] - '0');
            }
        }


        int carry = 0;
        for(int num: v){
            // O(n + m) time
            ans += ((num + carry) % 10 + '0'); // '8'
            carry = (num + carry) / 10;
        }
        if(carry > 0){
            ans += (carry + '0');
        }
        while(ans.size() > 1 && ans.back() == '0') ans.pop_back();


        reverse(ans.begin(), ans.end());
        return ans;
    }
};
