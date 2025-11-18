class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;

        // Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Dijkstra arrays
        vector<long long> dist(V, 1e18);
        vector<int> ways(V, 0);

        // Min heap: {dist, node}
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &p : adj[u]) {
                int v = p.first;
                long long wt = p.second;

                // Case 1: shorter path found
                if(dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }

                // Case 2: equal shortest path
                else if(dist[v] == dist[u] + wt) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[V-1];
    }
};
