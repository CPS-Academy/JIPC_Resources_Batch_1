class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        string result = "";
        int carry = 0;
        int result_digit_value, result_digit_unit_value;
        int add1, add2;
        // time O(max(n, m))
        // space O(1)
        while(i >= 0 || j >= 0){ // at least 1 string is still valid
            add1 = (i < 0) ? 0 : (num1[i] - '0'); // leading 0 if i < 0
            add2 = (j < 0) ? 0 : (num2[j] - '0');
            result_digit_value = add1 + add2 + carry; // 0-19


            result_digit_unit_value = result_digit_value % 10;
            carry = (result_digit_value >= 10) ? 1 : 0;


            result += (result_digit_unit_value + '0'); // 9 -> '9', 2 -> '2'
            // '0' = 48
            // '1' = 49
            // '2' = 50
            i--;
            j--;


        }
        // both i < 0 and j < 0
        if(carry > 0){
            result += (carry + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
