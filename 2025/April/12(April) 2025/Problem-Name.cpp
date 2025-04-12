class Solution {
  public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor) {
        int n = image.size();
        int m = image[0].size();

        // Base case: check bounds and color match
        if (r < 0 || r >= n || c < 0 || c >= m || image[r][c] != color)
            return;

        // Fill the color
        image[r][c] = newColor;

        // Explore neighbors
        dfs(image, r + 1, c, color, newColor); // down
        dfs(image, r - 1, c, color, newColor); // up
        dfs(image, r, c + 1, color, newColor); // right
        dfs(image, r, c - 1, color, newColor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) {
            dfs(image, sr, sc, color, newColor);
        }
        return image;
    }
};
