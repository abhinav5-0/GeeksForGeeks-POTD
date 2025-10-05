#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string path, vector<vector<int>> &vis) {
        // If destination is reached
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        // Direction arrays: D, L, R, U
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        char dir[] = {'D', 'L', 'R', 'U'};

        // Try all 4 possible directions
        for (int k = 0; k < 4; k++) {
            int nexti = i + di[k];
            int nextj = j + dj[k];

            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && 
                !vis[nexti][nextj] && maze[nexti][nextj] == 1) {
                vis[i][j] = 1;
                solve(nexti, nextj, maze, n, ans, path + dir[k], vis);
                vis[i][j] = 0; // Backtrack
            }
        }
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans; // No path possible

        solve(0, 0, maze, n, ans, "", vis);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Example usage
int main() {
    Solution obj;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> res = obj.ratInMaze(maze);
    for (auto &path : res) cout << path << " ";
    return 0;
}
