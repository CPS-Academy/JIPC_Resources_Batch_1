class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> baseOfPascalsTriangle;
        baseOfPascalsTriangle.push_back({1});
        for(int i = 0; i < rowIndex; i++) {
            vector<int> newBaseOfPascalTriangle;
            newBaseOfPascalTriangle.push_back(1);
            for(int i = 1; i < baseOfPascalsTriangle.size(); i++) {
                int valueAbove = baseOfPascalsTriangle[i];
                int valueAboveLeft = baseOfPascalsTriangle[i - 1];
                newBaseOfPascalTriangle.push_back(valueAbove + valueAboveLeft);
            }
            newBaseOfPascalTriangle.push_back(1);
            baseOfPascalsTriangle = newBaseOfPascalTriangle;
        }
        return baseOfPascalsTriangle;
    }
};
