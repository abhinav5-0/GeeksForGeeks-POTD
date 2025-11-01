class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);

        // Build adjacency list and indegree count
        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        // Push all courses with 0 indegree
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            // Reduce indegree of adjacent courses
            for (int next : adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        // If we could schedule all courses
        if (order.size() == n)
            return order;

        // Cycle detected — impossible to finish all courses
        return {};
    }
};
