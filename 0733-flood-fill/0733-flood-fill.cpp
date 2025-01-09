class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int originalColor, int newColor) {
        int n = image.size();
        int m = image[0].size();

        if (sr < 0 || sr >= n || sc < 0 || sc >= m || image[sr][sc] != originalColor) {
            return;
        }

        image[sr][sc] = newColor;

        dfs(image, sr - 1, sc, originalColor, newColor);
        dfs(image, sr, sc + 1, originalColor, newColor);
        dfs(image, sr + 1, sc, originalColor, newColor);
        dfs(image, sr, sc - 1, originalColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if (originalColor != newColor) {
            dfs(image, sr, sc, originalColor, newColor);
        }
        return image;
    }
};
