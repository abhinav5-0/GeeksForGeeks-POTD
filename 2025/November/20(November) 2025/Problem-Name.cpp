class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {

        const int INF = 1e9;
        vector<vector<int>> dist(26, vector<int>(26, INF));

        // Distance to self is zero
        for (int i = 0; i < 26; i++) dist[i][i] = 0;

        // Add transformation edges
        for (int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }

        // Floyd–Warshall: compute all pairs shortest paths
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        long long ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';

            if (a == b) continue;

            int best = INF;

            // Try converting both to some common letter c
            for (int c = 0; c < 26; c++) {
                if (dist[a][c] < INF && dist[b][c] < INF) {
                    best = min(best, dist[a][c] + dist[b][c]);
                }
            }

            if (best == INF) return -1;
            ans += best;
        }

        return ans;
    }
};
