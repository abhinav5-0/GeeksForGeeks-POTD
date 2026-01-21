import java.util.*;

class Solution {
    public static int[] calculateSpan(int[] arr) {
        int n = arr.length;
        int[] span = new int[n];
        Stack<Integer> st = new Stack<>(); // stores indices

        for (int i = 0; i < n; i++) {
            // Pop while current price is higher or equal
            while (!st.isEmpty() && arr[st.peek()] <= arr[i]) {
                st.pop();
            }

            // If stack empty, span is i+1
            span[i] = st.isEmpty() ? (i + 1) : (i - st.peek());

            // Push current index
            st.push(i);
        }
        return span;
    }
}
