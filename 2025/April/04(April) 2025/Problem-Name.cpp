class Solution {
  public:
    vector<int> parent;
    vector<int> rank;

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank
    bool unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return false; // cycle detected

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        parent.resize(V);
        rank.resize(V, 0);

        for (int i = 0; i < V; ++i) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (!unionSet(u, v)) {
                return true; // cycle detected
            }
        }

        return false;
    }
};
