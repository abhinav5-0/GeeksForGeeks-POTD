class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }

    void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = find(a, parent);
        b = find(b, parent);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }

    int minConnect(int V, vector<vector<int>>& edges) {
        int E = edges.size();

        // If not enough edges to connect all hospitals
        if (E < V - 1) return -1;

        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;

        // Count components using DSU
        for (auto& e : edges) {
            unite(e[0], e[1], parent, rank);
        }

        int components = 0;
        for (int i = 0; i < V; i++) {
            if (find(i, parent) == i)
                components++;
        }

        // Operations needed = number of components - 1
        return components - 1;
    }
};
