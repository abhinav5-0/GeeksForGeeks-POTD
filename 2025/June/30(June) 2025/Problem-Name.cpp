class Solution {
  public:
    bool isPossible(vector<int> &arr, int k, int w, int target) {
        int n = arr.size();
        vector<int> water(n + 1, 0); // Difference array
        long long totalWater = 0, currentWater = 0;

        for (int i = 0; i < n; ++i) {
            currentWater += water[i];
            int effectiveHeight = arr[i] + currentWater;

            if (effectiveHeight < target) {
                int needed = target - effectiveHeight;
                totalWater += needed;
                if (totalWater > k) return false;

                currentWater += needed;
                if (i + w < n)
                    water[i + w] -= needed;
            }
        }
        return true;
    }

    int maxMinHeight(vector<int> &arr, int k, int w) {
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k; // Max possible height achievable
        int answer = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, w, mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer;
    }
};
