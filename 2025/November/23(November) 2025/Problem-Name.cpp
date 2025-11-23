class Solution {
public:
    vector<int> parent, rankv;
    
    int findp(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findp(parent[x]);
    }
    
    void unionp(int a, int b) {
        a = findp(a);
        b = findp(b);
        if (a != b) {
            if (rankv[a] < rankv[b]) swap(a, b);
            parent[b] = a;
            if (rankv[a] == rankv[b]) rankv[a]++;
        }
    }

    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        
        int OFFSET = 10001;    // shift columns
        
        parent.resize(20005);
        rankv.resize(20005, 0);
        
        for (int i = 0; i < 20005; i++)
            parent[i] = i;

        unordered_set<int> used;  // track active nodes
        
        for (auto &s : stones) {
            int r = s[0];
            int c = s[1] + OFFSET;  // shift column
            
            unionp(r, c);
            used.insert(r);
            used.insert(c);
        }
        
        int components = 0;
        for (int x : used) {
            if (findp(x) == x) components++;
        }
        
        return n - components;
    }
};
