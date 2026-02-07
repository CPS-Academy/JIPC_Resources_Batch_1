class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> lastDuplicateChar;
        for(auto& ch: s) {
            if(!lastDuplicateChar.empty() && lastDuplicateChar.top() == ch) {
                lastDuplicateChar.pop();
            }
            else{
                lastDuplicateChar.push(ch);
            }
        }

        string finalString = "";
        while(!lastDuplicateChar.empty()) {
            finalString.push_back(lastDuplicateChar.top());
            lastDuplicateChar.pop();
        }
        reverse(finalString.begin(), finalString.end());
        return finalString;
    }
};

class Solution {
private:
    const static char INVALID = '0';
public:
    string removeDuplicates(string s) {
        stack<int> lastIndex;
        for(int i = 0; i < s.size(); i++) {
            if(!lastIndex.empty() && s[ lastIndex.top() ] == s[i]) {
                s[ lastIndex.top() ] = s[i] = INVALID;
                lastIndex.pop();
            }
            else{
                lastIndex.push(i);
            }
        }

        string finalString = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != INVALID) {
                finalString += s[i];
            }
        }

        return finalString;
    }
};

class Solution {
private:
    const static int INVALID = -1;
public:
    // xz[yy]zx -> xzzx -> xx -> ""
    string removeDuplicates(string s) {
        int operationCount = s.size()/2;
        while(operationCount--) {
            int duplicateIndex = -1;
            for(int i = 1; i < s.size(); i++) {
                if(s[i - 1] == s[i]) {
                    duplicateIndex = i - 1;
                    break;
                }
            }

            if(duplicateIndex == INVALID) {
                break;
            }

            string stringAfterOperation;
            for(int i = 0; i < s.size(); i++) {
                if(duplicateIndex != i && duplicateIndex + 1 != i) {
                    stringAfterOperation += s[i];
                }
            }
            s = stringAfterOperation;
        }
        return s;
    }
};
