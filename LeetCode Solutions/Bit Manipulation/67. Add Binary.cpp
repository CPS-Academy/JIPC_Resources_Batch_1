class Solution {
public:
    string addBinary(string a, string b) {
        string ans_rev = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());


        int i = 0;
        // phase 1 and 2 combined, any strings present
        int carry = 0;
        int aa, bb;
        int result_bit_value, result_bits_unit_bit;
        while(i < a.size() || i < b.size())
        {
            aa = (i < a.size()) ? (a[i] - '0') : 0;
            bb = (i < b.size()) ? (b[i] - '0') : 0;
            result_bit_value = aa + bb + carry; // 0,1,2,3


            result_bits_unit_bit = result_bit_value % 2; // 0,1
            carry = (result_bit_value >= 2) ? 1 : 0;


            ans_rev += (result_bits_unit_bit + '0'); // '0', '1'


            i++;
            // '0' = 48
            // '1' = 49
            // '2' = 50...
        }
        // a and b both are complete
        // now to see if carry is present
        if(carry > 0){
            ans_rev += (carry + '0');
        }


        // time O(n)
        // space O(1)


        reverse(ans_rev.begin(), ans_rev.end());
        return ans_rev;
    }
};
