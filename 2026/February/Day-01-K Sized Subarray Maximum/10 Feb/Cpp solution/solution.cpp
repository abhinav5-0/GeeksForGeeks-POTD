class Solution {
public:
    bool canEat(vector<int>& arr, int k, int s) {
        long long hours = 0;
        for (int bananas : arr) {
            hours += (bananas + s - 1) / s;   // ceil(bananas / s)
        }
        return hours <= k;
    }

    int kokoEat(vector<int>& arr, int k) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canEat(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
