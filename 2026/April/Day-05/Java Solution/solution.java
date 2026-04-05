class Solution {
    public int totalWays(int[] arr, int target) {
        int sum = 0;
        for (int x : arr) sum += x;

        if ((sum + target) % 2 != 0 || Math.abs(target) > sum) return 0;

        int P = (sum + target) / 2;

        int[] dp = new int[P + 1];
        dp[0] = 1;

        for (int num : arr) {
            for (int j = P; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[P];
    }
}
