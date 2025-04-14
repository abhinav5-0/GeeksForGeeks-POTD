class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> indegree;
        
        // Step 1: Initialize graph
        for (const string &word : words) {
            for (char c : word) {
                graph[c]; // ensure every character is in the graph
                indegree[c]; // initialize indegree
            }
        }

        // Step 2: Build graph from adjacent word pairs
        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            bool found_diff = false;
            for (int j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    graph[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    found_diff = true;
                    break;
                }
            }
            // Invalid case: prefix problem like ["abc", "ab"]
            if (!found_diff && w1.length() > w2.length())
                return "";
        }

        // Step 3: Topological Sort (Kahn's Algorithm)
        queue<char> q;
        for (auto &p : indegree) {
            if (p.second == 0)
                q.push(p.first);
        }

        string result;
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;

            for (char neighbor : graph[curr]) {
                if (--indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If result doesn't contain all characters, cycle exists
        if (result.size() != graph.size())
            return "";

        return result;
    }
};
