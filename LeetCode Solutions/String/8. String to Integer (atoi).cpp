class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int n = s.size();

        while(index < n && s[index] == ' ') {
            index++;
        }

        int sign = 1;
        if(index < n && s[index] == '+') {
            sign = 1;
            index++;
        } 
        else if(index < n && s[index] == '-') {
            sign = -1;
            index++;
        }

        int resultValue = 0;
        while(index < n && isdigit(s[index])) {
            int digit = s[index] - '0';

            if(resultValue > INT_MAX/10 || (resultValue == INT_MAX/10 && digit > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            resultValue = 10*resultValue + digit;
            index++;
        }

        return sign*resultValue;
    }
};
