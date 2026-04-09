import java.util.*;

class Solution {
    public ArrayList<Integer> intersection(int[] a, int[] b) {
        int i = 0, j = 0;
        ArrayList<Integer> res = new ArrayList<>();

        while (i < a.length && j < b.length) {
            if (a[i] == b[j]) {
                if (res.isEmpty() || res.get(res.size() - 1) != a[i]) {
                    res.add(a[i]);
                }
                i++;
                j++;
            }
            else if (a[i] < b[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return res;
    }
}
