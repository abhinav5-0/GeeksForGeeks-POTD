import java.util.*;

class Solution {
    public int[] findClosestPair(int[] arr1, int[] arr2, int x) {
        int n = arr1.length;
        int m = arr2.length;
        
        int left = 0;
        int right = m - 1;
        
        int minDiff = Integer.MAX_VALUE;
        int[] result = new int[2];
        
        while (left < n && right >= 0) {
            int sum = arr1[left] + arr2[right];
            int diff = Math.abs(sum - x);
            
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = arr1[left];
                result[1] = arr2[right];
            }
            
            if (sum > x) {
                right--;
            } else {
                left++;
            }
        }
        
        return result;
    }
}
