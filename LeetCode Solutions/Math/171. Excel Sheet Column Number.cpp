class Solution {
public:
    int titleToNumber(string columnTitle) {
        // A       B      D
        // 1*26^2  2*26   4*1
        // time O(n), space O(1)
        int mul = 1;
        int columnNumber = 0;
        for(int i = columnTitle.size() - 1; i >= 0; i--){
            columnNumber += (columnTitle[i] - 'A' + 1) * mul;
            mul *= 26;
        }
        return columnNumber;
    }
};
