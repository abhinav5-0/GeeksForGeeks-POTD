class Solution {
    public int countSubset(int[] arr, int k) {
        int n = arr.length;
        int mid = n / 2;

        int[] left = new int[mid];
        int[] right = new int[n - mid];

        for (int i = 0; i < mid; i++) left[i] = arr[i];
        for (int i = mid; i < n; i++) right[i - mid] = arr[i];

        HashMap<Long, Integer> map = new HashMap<>();

        // Left half subset sums
        for (int mask = 0; mask < (1 << left.length); mask++) {
            long sum = 0;
            for (int i = 0; i < left.length; i++) {
                if ((mask & (1 << i)) != 0)
                    sum += left[i];
            }
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }

        int ans = 0;

        // Right half subset sums
        for (int mask = 0; mask < (1 << right.length); mask++) {
            long sum = 0;
            for (int i = 0; i < right.length; i++) {
                if ((mask & (1 << i)) != 0)
                    sum += right[i];
            }
            ans += map.getOrDefault((long)k - sum, 0);
        }

        return ans;
    }
}
