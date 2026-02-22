import java.util.*;

class Solution {
    public long subarrayXor(int[] arr, int k) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        int xr = 0;
        long count = 0;

        for (int num : arr) {
            xr ^= num;

            if (xr == k)
                count++;

            if (freq.containsKey(xr ^ k))
                count += freq.get(xr ^ k);

            freq.put(xr, freq.getOrDefault(xr, 0) + 1);
        }

        return count;
    }
}
