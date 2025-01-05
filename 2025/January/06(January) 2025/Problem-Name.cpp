class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        if (n < 2) return {};

        sort(arr.begin(), arr.end());

        int closestDiff = INT_MAX;
        int maxAbsDiff = INT_MIN;
        vector<int> result;

        int left = 0, right = n - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];
            int diff = abs(target - sum);

            if (diff < closestDiff || (diff == closestDiff && abs(arr[right] - arr[left]) > maxAbsDiff)) {
                closestDiff = diff;
                maxAbsDiff = abs(arr[right] - arr[left]);
                result = {arr[left], arr[right]};
            }

            if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }

        return result;
    }
};
