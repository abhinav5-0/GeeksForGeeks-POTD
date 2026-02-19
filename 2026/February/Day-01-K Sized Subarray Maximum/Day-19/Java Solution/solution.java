import java.util.*;

class Solution {
    public List<Integer> missinRange(int[] arr, int low, int high) {
        Set<Integer> set = new HashSet<>();
        for(int num : arr) {
            set.add(num);
        }
        
        List<Integer> result = new ArrayList<>();
        
        for(int i = low; i <= high; i++) {
            if(!set.contains(i)) {
                result.add(i);
            }
        }
        
        return result;
    }
}
