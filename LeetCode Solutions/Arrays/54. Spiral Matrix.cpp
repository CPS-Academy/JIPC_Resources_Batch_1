class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int weidth = matrix[0].size();

        int left = 0;
        int right = weidth - 1;
        int top = 0;
        int bottom = height - 1;

        vector<int> spirallyTraversedValues;
        while(left <= right && top <= bottom) {

            for(int i = left; i <= right; i++) {
                spirallyTraversedValues.push_back(matrix[top][i]);
            }
            top++;

            for(int i = top; i <= bottom; i++) {
                spirallyTraversedValues.push_back(matrix[i][right]);
            }
            right--;

            if(!(left <= right && top <= bottom)) {
                break;
            }

            for(int i = right; i >= left; i--) {
                spirallyTraversedValues.push_back(matrix[bottom][i]);
            }
            bottom--;

            for(int i = bottom; i >= top; i--) {
                spirallyTraversedValues.push_back(matrix[i][left]);
            }
            left++;
        }

        return spirallyTraversedValues;
    }
};
