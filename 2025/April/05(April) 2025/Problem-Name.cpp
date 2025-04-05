class Solution {
  public:
    int n, m;
    vector<vector<bool>> visited;
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    bool isSafe(int x, int y, vector<vector<char>>& grid) {
        return (x >= 0 && x < n && y >= 0 && y < m &&
                grid[x][y] == 'L' && !visited[x][y]);
    }

    void dfs(int x, int y, vector<vector<char>>& grid) {
        visited[x][y] = true;
        for (int k = 0; k < 8; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if (isSafe(newX, newY, grid)) {
                dfs(newX, newY, grid);
            }
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'L' && !visited[i][j]) {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};
