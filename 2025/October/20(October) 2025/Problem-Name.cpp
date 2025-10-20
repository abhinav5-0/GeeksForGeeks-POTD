class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> catalan(n + 1, 0);
        catalan[0] = catalan[1] = 1;

        // Compute Catalan numbers
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }

        // Sort array to respect BST ordering
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        
        unordered_map<int, int> bstCount;

        for (int i = 0; i < n; i++) {
            int left = i;             // elements smaller
            int right = n - i - 1;    // elements greater
            bstCount[sorted[i]] = catalan[left] * catalan[right];
        }

        // Return counts in original order
        vector<int> result;
        for (int val : arr) {
            result.push_back(bstCount[val]);
        }

        return result;
    }
};
