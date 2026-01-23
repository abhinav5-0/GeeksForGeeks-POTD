class Solution {
    public int maxPeople(int[] arr) {
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Stack<Integer> st = new Stack<>();

        // Left side
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && arr[st.peek()] < arr[i]) {
                left[i]++;
                st.pop();
            }
            if (!st.isEmpty()) left[i]++;
            st.push(i);
        }

        st.clear();

        // Right side
        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && arr[st.peek()] < arr[i]) {
                right[i]++;
                st.pop();
            }
            if (!st.isEmpty()) right[i]++;
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = Math.max(ans, left[i] + right[i] + 1);

        return ans;
    }
}
