class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        auto countLessEqual = [&](int x) {
            int count = 0;
            for (int i = 1; i <= m; ++i) {
                count += std::min(x / i, n);
            }
            return count;
        };

        int low = 1, high = m * n, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (countLessEqual(mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
