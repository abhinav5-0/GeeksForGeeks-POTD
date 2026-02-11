import java.util.*;

class Solution {
    public long minCost(int[] heights, int[] cost) {
        int n = heights.length;
        
        int[][] arr = new int[n][2];
        for(int i = 0; i < n; i++) {
            arr[i][0] = heights[i];
            arr[i][1] = cost[i];
        }
        
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);
        
        long totalCost = 0;
        for(int i = 0; i < n; i++)
            totalCost += arr[i][1];
        
        // Find weighted median
        long curr = 0;
        int target = 0;
        for(int i = 0; i < n; i++) {
            curr += arr[i][1];
            if(curr >= (totalCost + 1) / 2) {
                target = arr[i][0];
                break;
            }
        }
        
        // Calculate minimum cost
        long answer = 0;
        for(int i = 0; i < n; i++) {
            answer += (long)Math.abs(heights[i] - target) * cost[i];
        }
        
        return answer;
    }
}
