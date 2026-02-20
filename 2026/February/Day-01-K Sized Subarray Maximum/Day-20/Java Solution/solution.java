import java.util.*;

class Solution {
    String findLargest(int[] arr) {
        
        String[] nums = new String[arr.length];
        
        // Convert integers to strings
        for (int i = 0; i < arr.length; i++) {
            nums[i] = String.valueOf(arr[i]);
        }
        
        // Custom sort
        Arrays.sort(nums, (a, b) -> (b + a).compareTo(a + b));
        
        // Edge case: if largest is "0"
        if (nums[0].equals("0"))
            return "0";
        
        // Concatenate result
        StringBuilder result = new StringBuilder();
        for (String s : nums) {
            result.append(s);
        }
        
        return result.toString();
    }
}
