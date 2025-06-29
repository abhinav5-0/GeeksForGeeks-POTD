class Solution {
  public:
    int splitArray(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {
                result = mid;       // Try for better (smaller) answer
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }

    // Helper to check if we can split into ≤ k subarrays with max sum ≤ mid
    bool isPossible(vector<int>& arr, int k, int mid) {
        int count = 1;
        int currentSum = 0;

        for (int i = 0; i < arr.size(); ++i) {
            if (currentSum + arr[i] > mid) {
                count++;
                currentSum = arr[i];

                if (count > k) return false;
            } else {
                currentSum += arr[i];
            }
        }

        return true;
    }
};
