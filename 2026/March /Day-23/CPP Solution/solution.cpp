class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> next(V, -1);

        // Build direct mapping
        for (auto &e : edges) {
            next[e[0]] = e[1];
        }

        vector<int> vis(V, 0);
        int ans = -1;

        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;

            unordered_map<int, int> step;
            int node = i, cnt = 0;

            while (node != -1 && !vis[node]) {
                vis[node] = 1;
                step[node] = cnt++;
                node = next[node];

                if (node != -1 && step.count(node)) {
                    ans = max(ans, cnt - step[node]);
                    break;
                }
            }
        }

        return ans;
    }
};
