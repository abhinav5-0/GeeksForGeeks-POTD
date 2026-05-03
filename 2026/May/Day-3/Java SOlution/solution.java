import java.util.*;

class Solution {
    public int[] sortBySetBitCount(int[] arr) {
        Integer[] temp = Arrays.stream(arr).boxed().toArray(Integer[]::new);

        Arrays.sort(temp, (a, b) -> {
            int countA = Integer.bitCount(a);
            int countB = Integer.bitCount(b);

            // Descending order of set bits
            if (countA != countB)
                return countB - countA;

            return 0; // stable order maintained
        });

        // Convert back to int[]
        for (int i = 0; i < arr.length; i++)
            arr[i] = temp[i];

        return arr;
    }
}
