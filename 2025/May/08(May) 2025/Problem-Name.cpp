class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return -1; // invalid case

        // Estimate the common difference (taking min of adjacent diffs to be safe)
        int diff = (arr[n - 1] - arr[0]) / n;

        // Traverse to find the missing element
        for (int i = 1; i < n; i++) {
            int expected = arr[i - 1] + diff;
            if (arr[i] != expected) {
                return expected;
            }
        }

        // If all elements are in place, return the next element in AP
        return arr[n - 1] + diff;
    }
};
