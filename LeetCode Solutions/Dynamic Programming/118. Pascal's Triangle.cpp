class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalsTriangle;
        pascalsTriangle.push_back({1});
        for(int i = 1; i < numRows; i++) {
            vector<int> newTriangleBase;
            newTriangleBase.push_back(1);
            for(int i = 1; i < pascalsTriangle.back().size(); i++) {
                newTriangleBase.push_back(pascalsTriangle.back()[i] + pascalsTriangle.back()[i - 1]);
            }
            newTriangleBase.push_back(1);
            pascalsTriangle.push_back(newTriangleBase);
        }
        return pascalsTriangle;
    }
};
