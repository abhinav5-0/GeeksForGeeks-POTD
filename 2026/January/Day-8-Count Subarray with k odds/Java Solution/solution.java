import java.util.*;

class Solution {
    public int countSubarrays(int[] arr, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        freq.put(0, 1);
        
        int prefixSum = 0, count = 0;
        
        for (int num : arr) {
            prefixSum += (num % 2); // odd -> 1
            
            count += freq.getOrDefault(prefixSum - k, 0);
            
            freq.put(prefixSum, freq.getOrDefault(prefixSum, 0) + 1);
        }
        
        return count;
    }
}
