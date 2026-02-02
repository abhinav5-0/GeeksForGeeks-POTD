class Solution {
    int kadaneMax(int[] arr) {
        int curr = arr[0], best = arr[0];
        for (int i = 1; i < arr.length; i++) {
            curr = Math.max(arr[i], curr + arr[i]);
            best = Math.max(best, curr);
        }
        return best;
    }

    int kadaneMin(int[] arr) {
        int curr = arr[0], best = arr[0];
        for (int i = 1; i < arr.length; i++) {
            curr = Math.min(arr[i], curr + arr[i]);
            best = Math.min(best, curr);
        }
        return best;
    }

    int maxCircularSum(int[] arr) {
        int normalMax = kadaneMax(arr);

        // All elements negative
        if (normalMax < 0) return normalMax;

        int totalSum = 0;
        for (int x : arr) totalSum += x;

        int minSubarray = kadaneMin(arr);

        return Math.max(normalMax, totalSum - minSubarray);
    }
}
