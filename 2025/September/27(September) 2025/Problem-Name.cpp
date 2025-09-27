class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> isFlipped(n, 0);  // track flip starts
        int flipCount = 0, ops = 0;

        for (int i = 0; i < n; i++) {
            // remove expired flip effect
            if (i >= k) {
                flipCount ^= isFlipped[i - k];
            }

            // if current bit after flips is 0 → must flip
            if ((arr[i] ^ flipCount) == 0) {
                if (i + k > n) return -1; // cannot flip outside array
                ops++;
                flipCount ^= 1; // start new flip
                isFlipped[i] = 1;
            }
        }
        return ops;
    }
};
