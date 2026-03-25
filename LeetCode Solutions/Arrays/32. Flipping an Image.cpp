class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int height = image.size(), weidth = image[0].size();
        for(int row = 0; row < height; row++) {
            for(int start = 0, end = weidth - 1; start <= end; start++, end--) {
                int flipedStartValue = (image[row][start]^1);
                image[row][start] = (image[row][end]^1);
                image[row][end] = flipedStartValue;
            }
        }
        return image;
    }
};
