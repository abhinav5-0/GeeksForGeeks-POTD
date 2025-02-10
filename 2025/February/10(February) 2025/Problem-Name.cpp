class Solution {
  public:
    int countPaths(Node* root, int k, unordered_map<int, int>& prefixSum, int currSum) {
        if (!root) return 0;

        // Update current sum
        currSum += root->data;
        
        // Check if there's a prefix sum that makes the path sum equal to k
        int count = 0;
        if (prefixSum.find(currSum - k) != prefixSum.end())
            count += prefixSum[currSum - k];

        // If current sum itself equals k, count it as a valid path
        if (currSum == k) count++;

        // Store current prefix sum in the map
        prefixSum[currSum]++;
        
        // Recur for left and right subtrees
        count += countPaths(root->left, k, prefixSum, currSum);
        count += countPaths(root->right, k, prefixSum, currSum);

        // Backtrack: Remove current sum from the map
        prefixSum[currSum]--;
        
        return count;
    }

    int sumK(Node* root, int k) {
        unordered_map<int, int> prefixSum;
        return countPaths(root, k, prefixSum, 0);
    }
};
