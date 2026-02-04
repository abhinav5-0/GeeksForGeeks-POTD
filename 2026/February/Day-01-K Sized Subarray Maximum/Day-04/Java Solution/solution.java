class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        int ans = 0;

        // Left moving ants
        for (int x : left) {
            ans = Math.max(ans, x);
        }

        // Right moving ants
        for (int x : right) {
            ans = Math.max(ans, n - x);
        }

        return ans;
    }
}
