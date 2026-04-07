class Solution {
public:
    int minSwaps(string s) {
        int openingCount = 0;
        for(auto& ch: s) {
            if(ch == '[') {
                openingCount++;
            }
            else if(openingCount > 0) {
                openingCount--;
            }
        }
        return (openingCount + 1) / 2;
    }
};

class Solution {
public:
    int minSwaps(string s) {
        stack<char> openingBracketStack;
        for(auto& ch: s) {
            if(ch == '[') {
                openingBracketStack.push(ch);
            }
            else if(!openingBracketStack.empty()) {
                openingBracketStack.pop();
            }
        }
        return (openingBracketStack.size() + 1) / 2;
    }
};
