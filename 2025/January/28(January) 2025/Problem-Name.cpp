class Solution {
  public:
    vector<string> findPermutation(string &s) {
        set<string> uniquePermutations; // To store unique permutations
        string currentPermutation; // Temporary string to store current permutation
        vector<bool> used(s.size(), false); // To track used characters during backtracking
        sort(s.begin(), s.end()); // Sort the string to handle duplicates effectively
        
        // Helper function for backtracking
        function<void()> backtrack = [&]() {
            if (currentPermutation.size() == s.size()) {
                uniquePermutations.insert(currentPermutation);
                return;
            }
            
            for (int i = 0; i < s.size(); ++i) {
                // Skip duplicate characters or already used characters
                if (used[i] || (i > 0 && s[i] == s[i - 1] && !used[i - 1])) continue;
                
                used[i] = true;
                currentPermutation.push_back(s[i]);
                backtrack();
                used[i] = false;
                currentPermutation.pop_back();
            }
        };

        backtrack();
        
        // Convert the set to a vector
        return vector<string>(uniquePermutations.begin(), uniquePermutations.end());
    }
};
