class Solution {
public:
    bool checkValidString(string s) {
        int unbalanceCount = 0;
        for(auto& parenthesis: s) {
            if(parenthesis == '(' || parenthesis == '*') {
                unbalanceCount++;
            }
            else if(unbalanceCount > 0){
                unbalanceCount--;
            }
            else {
                return false;
            }
        }
        unbalanceCount = 0; 
        for(int i = s.size() - 1; i >= 0; i--) {
            char parenthesis = s[i];
            if(parenthesis == ')' || parenthesis == '*') {
                unbalanceCount++;
            }
            else if(unbalanceCount > 0){
                unbalanceCount--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
