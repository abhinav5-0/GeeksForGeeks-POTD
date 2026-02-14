class Solution {

    private boolean isPossible(int[] arr, int k, long maxTime) {
        long currSum = 0;
        int painters = 1;

        for (int i = 0; i < arr.length; i++) {
            if (currSum + arr[i] <= maxTime) {
                currSum += arr[i];
            } else {
                painters++;
                currSum = arr[i];

                if (painters > k)
                    return false;
            }
        }
        return true;
    }

    public int minTime(int[] arr, int k) {
        long low = 0, high = 0;

        for (int x : arr) {
            high += x;
            low = Math.max(low, x);
        }

        long ans = high;

        while (low <= high) {
            long mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int) ans;
    }
}
