import java.util.*;

class Solution {
    public int countAtMostK(int[] arr, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        int left = 0;
        long ans = 0;

        for (int right = 0; right < arr.length; right++) {
            freq.put(arr[right], freq.getOrDefault(arr[right], 0) + 1);

            while (freq.size() > k) {
                freq.put(arr[left], freq.get(arr[left]) - 1);
                if (freq.get(arr[left]) == 0)
                    freq.remove(arr[left]);
                left++;
            }

            ans += (right - left + 1);
        }
        return (int) ans;
    }
}
