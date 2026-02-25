import java.util.*;

class Solution {
    public int longestSubarray(int[] arr, int k) {
        int n = arr.length;
        
        HashMap<Integer, Integer> map = new HashMap<>();
        int prefix = 0;
        int maxLen = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > k)
                prefix += 1;
            else
                prefix -= 1;
            
            if(prefix > 0)
                maxLen = i + 1;
            
            if(!map.containsKey(prefix))
                map.put(prefix, i);
            
            if(map.containsKey(prefix - 1))
                maxLen = Math.max(maxLen, i - map.get(prefix - 1));
        }
        
        return maxLen;
    }
}
