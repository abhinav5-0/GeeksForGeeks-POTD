import java.util.*;

class Solution {
    public int overlapInt(int[][] arr) {
        int n = arr.length;
        
        int[] start = new int[n];
        int[] end = new int[n];
        
        for(int i = 0; i < n; i++) {
            start[i] = arr[i][0];
            end[i] = arr[i][1];
        }
        
        Arrays.sort(start);
        Arrays.sort(end);
        
        int i = 0, j = 0;
        int currOverlap = 0, maxOverlap = 0;
        
        while(i < n && j < n) {
            if(start[i] <= end[j]) {
                currOverlap++;
                maxOverlap = Math.max(maxOverlap, currOverlap);
                i++;
            } else {
                currOverlap--;
                j++;
            }
        }
        
        return maxOverlap;
    }
}
