#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
        visited[node] = true;
        result.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, adj, visited, result);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> result;
        int V = adj.size();
        vector<bool> visited(V, false);
        
        dfsUtil(0, adj, visited, result);
        
        return result;
    }
};

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
