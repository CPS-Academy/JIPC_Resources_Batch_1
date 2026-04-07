class Solution {
public:
    string makeGood(string s) {
        int L = 0;
        for(int R = 0; R < s.size(); R++) {
            if(L > 0 && abs(s[R] - s[L - 1]) == 32) {
                L--;
            }
            else {
                swap(s[L], s[R]);
                L++;
            }
        }
        return s.substr(0, L);
    }
};


class Solution {
private:
    const static int UPPER_AND_LOWER_CHARACTER_DIFFERENCE = 32;
public:
    string makeGood(string s) {
        stack<char> characterStack;
        for(auto& ch: s) {
            if(!characterStack.empty() && abs(ch - characterStack.top()) == UPPER_AND_LOWER_CHARACTER_DIFFERENCE) {
                characterStack.pop();
            }
            else{
                characterStack.push(ch);
            }
        }

        string goodString = "";
        while(!characterStack.empty()) {
            goodString.push_back(characterStack.top());
            characterStack.pop();
        }
        reverse(goodString.begin(), goodString.end());
        return goodString;
    }
};
