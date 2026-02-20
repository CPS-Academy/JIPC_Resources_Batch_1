// Solution-1: Naive Recursive approach

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c: s) {
            if (c == '(') st.push(c);
            else {
                if(st.empty()) return false;
                st.pop();
            }
        }

        return st.empty();
    }

    void solve(int n, string s, vector<string> &ans) {
        if ( s.size() == n*2 ) {
            if (isValid(s)) ans.push_back(s);
            return;
        }

        solve( n, s + "(", ans );
        solve( n, s + ")", ans );
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, "", ans);
        return ans;
    }
};




// Solution-2: Optimized Recursive Approach

class Solution {
public:
    void solve(int n, string s, int left, int right, vector<string> &ans) {
        if ( s.size() == n*2 ) {
            ans.push_back(s);
            return;
        }

        if(left < n) {
            solve( n, s + "(", left+1, right, ans );
        }

        if(right < left) {
            solve( n, s + ")", left, right+1, ans );
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, "", 0, 0, ans);
        return ans;
    }
};




// Solution-3: Naive Queue Approach

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c: s) {
            if (c == '(') st.push(c);
            else {
                if(st.empty()) return false;
                st.pop();
            }
        }

        return st.empty();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        queue<string> q;
        q.push("");

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            if(cur.size() == n*2) {
                if(isValid(cur)) {
                    ans.push_back(cur);
                }

                continue;
            }

            q.push(cur + "(");
            q.push(cur + ")");
        }
        
        return ans;
    }
};


// Solution-4 Optimized Queue Approach

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c: s) {
            if (c == '(') st.push(c);
            else {
                if(st.empty()) return false;
                st.pop();
            }
        }

        return st.empty();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        queue<tuple<string, int,int>> q;
        q.push({"", 0, 0});

        while (!q.empty()) {
            auto [cur, left, right] = q.front();
            q.pop();

            if(cur.size() == n*2) {
                ans.push_back(cur);
                continue;
            }

            if(left < n) {
                q.push({cur + "(", left+1, right});
            }
            if(right < left) {
                q.push({cur + ")", left, right+1});
            }
        }
        
        return ans;
    }
};
