
class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        vector<long long> squared(n);

        // Step 1: Square all elements
        for (int i = 0; i < n; ++i) {
            squared[i] = 1LL * arr[i] * arr[i];
        }

        // Step 2: Sort the squared array
        sort(squared.begin(), squared.end());

        // Step 3: Fix one element as c^2 (from end to start)
        for (int i = n - 1; i >= 2; --i) {
            int left = 0;
            int right = i - 1;

            // Use two pointers to find a^2 + b^2 = c^2
            while (left < right) {
                long long sum = squared[left] + squared[right];
                if (sum == squared[i]) {
                    return true;  // Triplet found
                } else if (sum < squared[i]) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return false;  // No triplet found
    }
};
