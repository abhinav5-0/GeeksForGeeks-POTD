class Solution {
    private boolean canEat(int[] arr, int k, int s) {
        long hours = 0;
        for (int bananas : arr) {
            hours += (bananas + s - 1) / s;   // ceil division
        }
        return hours <= k;
    }

    public int kokoEat(int[] arr, int k) {
        int low = 1;
        int high = 0;

        for (int x : arr)
            high = Math.max(high, x);

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
}
