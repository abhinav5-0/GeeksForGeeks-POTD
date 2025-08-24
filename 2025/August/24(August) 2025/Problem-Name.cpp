class Solution {
  public:
    // Helper function to check if we can make m bouquets by 'day'
    bool canMake(vector<int>& arr, int k, int m, int day) {
        int count = 0, bouquets = 0;
        for (int bloom : arr) {
            if (bloom <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0; // reset after forming a bouquet
                }
            } else {
                count = 0; // reset if flower not bloomed
            }
        }
        return bouquets >= m;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {
        long long total = 1LL * k * m;
        if (arr.size() < total) return -1; // Not enough flowers
        
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMake(arr, k, m, mid)) {
                ans = mid;
                high = mid - 1; // try smaller days
            } else {
                low = mid + 1; // need more days
            }
        }
        return ans;
    }
};
