import java.util.*;

class Solution {
    public int[] nextFreqGreater(int[] arr) {
        int n = arr.length;
        HashMap<Integer, Integer> freq = new HashMap<>();
        for (int x : arr)
            freq.put(x, freq.getOrDefault(x, 0) + 1);

        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        Stack<Integer> st = new Stack<>(); // indices

        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && 
                   freq.get(arr[st.peek()]) <= freq.get(arr[i])) {
                st.pop();
            }

            if (!st.isEmpty())
                ans[i] = arr[st.peek()];

            st.push(i);
        }
        return ans;
    }
}
