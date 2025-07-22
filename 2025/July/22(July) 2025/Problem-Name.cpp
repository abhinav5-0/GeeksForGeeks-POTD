class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();

        // Place each number at its correct index if possible
        for (int i = 0; i < n; ++i) {
            while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // Find the first location where index doesn't match the value
        for (int i = 0; i < n; ++i) {
            if (arr[i] != i + 1)
                return i + 1;
        }

        // If all positions are correct, then smallest missing is n+1
        return n + 1;
    }
};
