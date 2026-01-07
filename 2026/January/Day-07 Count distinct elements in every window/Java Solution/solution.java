import java.util.*;

class Solution {
    ArrayList<Integer> countDistinct(int arr[], int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        ArrayList<Integer> result = new ArrayList<>();

        for (int i = 0; i < arr.length; i++) {
            // add current element
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);

            // remove element going out of window
            if (i >= k) {
                map.put(arr[i - k], map.get(arr[i - k]) - 1);
                if (map.get(arr[i - k]) == 0)
                    map.remove(arr[i - k]);
            }

            // window size reached
            if (i >= k - 1)
                result.add(map.size());
        }
        return result;
    }
}
