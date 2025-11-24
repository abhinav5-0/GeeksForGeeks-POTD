class Solution {
public:

    vector<int> parent, rnk;

    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){
        a = find(a); 
        b = find(b);
        if(a == b) return false;
        if(rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if(rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }

    int secondMST(int V, vector<vector<int>> &edges) {

        parent.resize(V);
        rnk.assign(V, 0);
        for(int i = 0; i < V; i++) parent[i] = i;

        // Sort edges by weight
        vector<array<int, 3>> ed;
        for(auto &e : edges) ed.push_back({e[2], e[0], e[1]});
        sort(ed.begin(), ed.end());

        vector<vector<pair<int, int>>> mst(V); // adjacency list {node, weight}

        int mstWeight = 0, usedEdges = 0;

        // Kruskal to build MST
        for(auto &e : ed){
            int w = e[0], u = e[1], v = e[2];
            if(unite(u, v)){
                mstWeight += w;
                usedEdges++;
                mst[u].push_back({v, w});
                mst[v].push_back({u, w});
            }
        }

        if(usedEdges != V - 1) return -1; // no MST exists

        // Prepare LCA with max-edge tracking
        const int LOG = 17; // since V <= 100
        vector<vector<int>> up(LOG, vector<int>(V, -1));
        vector<vector<int>> mx(LOG, vector<int>(V, 0));
        vector<int> depth(V, 0);

        function<void(int,int,int)> dfs = [&](int u, int p, int w){
            up[0][u] = p;
            mx[0][u] = w;
            for(auto &x : mst[u]){
                int v = x.first, wt = x.second;
                if(v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u, wt);
            }
        };

        dfs(0, -1, 0);

        for(int k = 1; k < LOG; k++){
            for(int v = 0; v < V; v++){
                if(up[k-1][v] == -1) {
                    up[k][v] = -1;
                    mx[k][v] = mx[k-1][v];
                } else {
                    up[k][v] = up[k-1][ up[k-1][v] ];
                    mx[k][v] = max(mx[k-1][v], mx[k-1][ up[k-1][v] ]);
                }
            }
        }

        auto maxEdgeOnPath = [&](int u, int v){
            if(depth[u] < depth[v]) swap(u, v);
            int maxW = 0;

            int diff = depth[u] - depth[v];
            for(int k = 0; k < LOG; k++){
                if(diff & (1 << k)){
                    maxW = max(maxW, mx[k][u]);
                    u = up[k][u];
                }
            }

            if(u == v) return maxW;

            for(int k = LOG-1; k >= 0; k--){
                if(up[k][u] != up[k][v]){
                    maxW = max({maxW, mx[k][u], mx[k][v]});
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            // last step to LCA
            maxW = max({maxW, mx[0][u], mx[0][v]});
            return maxW;
        };

        int ans = INT_MAX;

        // DSU refreshed to check MST edges
        parent.resize(V);
        rnk.assign(V, 0);
        for(int i = 0; i < V; i++) parent[i] = i;

        // Re-union while building MST again
        vector<bool> isMST(edges.size(), false);

        // Build MST again to mark MST edges
        sort(edges.begin(), edges.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });

        for(int i = 0; i < edges.size(); i++){
            if(unite(edges[i][0], edges[i][1])){
                isMST[i] = true;
            }
        }

        // Try non-MST edges
        for(int i = 0; i < edges.size(); i++){
            if(isMST[i]) continue;

            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            int mxW = maxEdgeOnPath(u, v);

            if(mxW == w) continue; // replacing same weight → gives same MST

            int newW = mstWeight + w - mxW;
            if(newW > mstWeight)
                ans = min(ans, newW);
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
