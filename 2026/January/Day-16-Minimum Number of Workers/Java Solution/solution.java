import java.util.*;

class Solution {
    public int minMen(int[] arr) {
        int n = arr.length;
        List<int[]> intervals = new ArrayList<>();

        // Create intervals
        for(int i = 0; i < n; i++) {
            if(arr[i] != -1) {
                int start = Math.max(0, i - arr[i]);
                int end = Math.min(n - 1, i + arr[i]);
                intervals.add(new int[]{start, end});
            }
        }

        // Sort intervals by start
        Collections.sort(intervals, (a, b) -> a[0] - b[0]);

        int cnt = 0;
        int i = 0;
        int covered = 0;

        // Greedy covering
        while(covered < n) {
            int farthest = covered;

            while(i < intervals.size() && intervals.get(i)[0] <= covered) {
                farthest = Math.max(farthest, intervals.get(i)[1] + 1);
                i++;
            }

            if(farthest == covered)
                return -1;

            cnt++;
            covered = farthest;
        }

        return cnt;
    }
}
