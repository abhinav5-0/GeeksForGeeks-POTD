class Solution {
    public int maxSubarrayXOR(int[] arr, int k) {
        int xr = 0;

        // XOR of first window
        for (int i = 0; i < k; i++) {
            xr ^= arr[i];
        }

        int ans = xr;

        // Sliding window
        for (int i = k; i < arr.length; i++) {
            xr ^= arr[i - k]; // remove left element
            xr ^= arr[i];     // add right element
            ans = Math.max(ans, xr);
        }

        return ans;
    }
}
