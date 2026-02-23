import java.util.*;

class Solution {
    public static ArrayList<Integer> findUnion(int a[], int b[]) {
        TreeSet<Integer> set = new TreeSet<>();
        
        // Insert elements of array a
        for(int num : a) {
            set.add(num);
        }
        
        // Insert elements of array b
        for(int num : b) {
            set.add(num);
        }
        
        return new ArrayList<>(set);
    }
}
